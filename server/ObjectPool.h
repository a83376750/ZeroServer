#pragma once
#include <vector>
#include <map>

#include "Header.h"

template<class Obj, class Mutex = std::mutex>
class ObjectPool
{
public:
	enum E_DEFAULT
	{
		DEFAULT_POOL_OBJ_COUNT = 1024
	};

	struct ObjectPlus
	{
		ObjectPlus() :m_obj(nullptr), m_is_use(false) {}
		bool m_is_use;
		Obj *m_obj;
	};

	typedef std::map<uint64_t, ObjectPlus*> UseObjMap;
	typedef std::vector<ObjectPlus*> ObjVec;

	ObjectPool(int count = E_DEFAULT::DEFAULT_POOL_OBJ_COUNT);
	virtual ~ObjectPool();
	ObjectPool& operator=(const ObjectPool &) = delete;
	ObjectPool(const ObjectPool &) = delete;

	void reserve(int count);
	void resize(int initCount);
	void clear();
	
	void push(Obj *obj);
	Obj* pop();
	bool empty()const;

	size_t use_obj_count()const;
	size_t free_obj_count()const;
	size_t total_obj_count()const;

protected:
	ObjectPlus* create(Obj *obj = nullptr)
	{
		ObjectPlus *p = nullptr;
		while ((p = new ObjectPlus()) == nullptr);
		while (obj == nullptr)
			obj = new Obj;
		p->m_obj = obj;
		return p;
	}

private:
	Mutex m_mutex;
	ObjVec m_obj_vec;
	UseObjMap m_use_obj_map;

	size_t m_use_obj_count;
	size_t m_free_obj_count;
	size_t m_total_obj_count;
	std::string m_name;
};

template<class Obj, class Mutex /*= std::mutex*/>
ObjectPool<Obj, Mutex>::ObjectPool(int count /*= E_DEFAULT::DEFAULT_POOL_OBJ_COUNT*/)
{
	m_name.clear();
	m_obj_vec.clear();
	m_obj_vec.clear();

	m_use_obj_count = 0;
	m_free_obj_count = 0;
	m_total_obj_count = 0;

	reserve(count);
}

template<class Obj, class Mutex /*= std::mutex*/>
ObjectPool<Obj, Mutex>::~ObjectPool()
{
	clear();
}

template<class Obj, class Mutex /*= std::mutex*/>
size_t ObjectPool<Obj, Mutex>::total_obj_count() const
{
	return m_total_obj_count;
}

template<class Obj, class Mutex /*= std::mutex*/>
size_t ObjectPool<Obj, Mutex>::free_obj_count() const
{
	return m_free_obj_count;
}

template<class Obj, class Mutex /*= std::mutex*/>
size_t ObjectPool<Obj, Mutex>::use_obj_count() const
{
	return m_use_obj_count;
}

template<class Obj, class Mutex /*= std::mutex*/>
void ObjectPool<Obj, Mutex>::reserve(int count)
{
	std::lock_guard<Mutex> lock(m_mutex);
	m_obj_vec.reserve(count);
}

template<class Obj, class Mutex /*= std::mutex*/>
bool ObjectPool<Obj, Mutex>::empty() const
{
	std::lock_guard<Mutex> lock(m_mutex);
	return m_obj_vec.empty();
}

template<class Obj, class Mutex /*= std::mutex*/>
void ObjectPool<Obj, Mutex>::resize(int initCount)
{
	std::lock_guard<Mutex> lock(m_mutex);
	initCount = initCount > 0 ? initCount : E_DEFAULT::DEFAULT_POOL_OBJ_COUNT;
	for (int i = 0; i < initCount; ++i)
	{
		ObjectPlus *p = create();
		m_obj_vec.emplace_back(p);
		m_use_obj_map[(size_t)(p->m_obj)] = p;
		printf("resize %d\n", (size_t)(p->m_obj));
		m_free_obj_count++;
		m_total_obj_count++;
	}
}

template<class Obj, class Mutex /*= std::mutex*/>
void ObjectPool<Obj, Mutex>::clear()
{
	std::lock_guard<Mutex> lock(m_mutex);
	ObjectPlus *obj = nullptr;
	while (m_obj_vec.empty() == false)
	{
		obj = m_obj_vec.back();
		m_obj_vec.pop_back();
		auto iter = m_use_obj_map.find((size_t)(obj->m_obj));
		if (iter != m_use_obj_map.end())
			m_use_obj_map.erase(iter);
		SAFE_DELETE(obj->m_obj);
		SAFE_DELETE(obj);
	}

	m_use_obj_count = 0;
	m_free_obj_count = 0;
	m_total_obj_count = 0;
	UseObjMap().swap(m_use_obj_map);
	ObjVec().swap(m_obj_vec);
}

template<class Obj, class Mutex>
void ObjectPool<Obj, Mutex>::push(Obj *obj)
{
	std::lock_guard<Mutex> lock(m_mutex);
	obj->reset();
	
	auto iter = m_use_obj_map.find((size_t)(obj));
	if (iter == m_use_obj_map.end())
	{
		ObjectPlus *p = create(obj);
		p->m_is_use = false;
		m_use_obj_map[(size_t)(obj)] = p;
		printf("plus %d\n", (size_t)(obj));
		m_obj_vec.push_back(p);
		m_total_obj_count++;
	}
	else
	{
		iter->second->m_is_use = false;
		m_obj_vec.push_back(iter->second);
	}
	m_free_obj_count++;
	m_use_obj_count--;
}

template<class Obj, class Mutex>
Obj* ObjectPool<Obj, Mutex>::pop()
{
	std::lock_guard<Mutex> lock(m_mutex);
	JUDGE_RETURN(m_obj_vec.empty(), nullptr);
	ObjectPlus *tmp = nullptr;
	tmp = m_obj_vec.back();
	m_obj_vec.pop_back();
	auto iter = m_use_obj_map.find((size_t)(tmp->m_obj));
	if (iter != m_use_obj_map.end())
		m_use_obj_map.erase(iter);
	while ((tmp->m_obj = new Obj()) == nullptr);
	tmp->m_is_use = true;
	m_free_obj_count--;
	m_use_obj_count++;
	return tmp->m_obj;
}

