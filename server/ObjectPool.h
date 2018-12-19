#pragma once

#include "ThreadLock.h"
#include <mutex>

struct DefaultObj
{
	unsigned char v[64];
};

struct DynaObj
{
	DynaObj(char *ptr, size_t len) : ptr_(ptr), len_(len) {}
	char *ptr_;
	size_t len_;
};



template<class Obj, class Mutex = NullMutex>
class ObjectPool
{
public:
	enum E_DEFAULT
	{
		DEFAULT_POOL_OBJ_COUNT = 1024
	};

	struct ObjectPlus
	{
		ObjectPlus() :obj(nullptr), is_use(false) {}
		bool is_use;
		Obj *obj;
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

	size_t UseObjCount()const;
	size_t FreeObjCount()const;
	size_t TotalObjCount()const;

	void DebugInfo();

protected:
	ObjectPlus* create(Obj *obj = nullptr)
	{
		ObjectPlus *p = nullptr;
		while ((p = new ObjectPlus()) == nullptr);
		while (obj == nullptr)
			obj = new Obj;
		p->obj = obj;
		return p;
	}

private:
	Mutex mutex_;
	ObjVec obj_vec_;
	UseObjMap use_obj_map_;

	size_t use_obj_count_;
	size_t free_obj_count_;
	size_t total_obj_count_;
	std::string name_;
};

template<class Obj, class Mutex /*= std::mutex*/>
void ObjectPool<Obj, Mutex>::DebugInfo()
{
	printf("free_obj_list_size_ = %u, use_obj_list_size_ = %u, used_size = %u\n",
		free_obj_count_, use_obj_map_.size(), use_obj_count_);
}

template<class Obj, class Mutex /*= std::mutex*/>
ObjectPool<Obj, Mutex>::ObjectPool(int count /*= E_DEFAULT::DEFAULT_POOL_OBJ_COUNT*/)
{
	name_.clear();
	obj_vec_.clear();
	obj_vec_.clear();

	use_obj_count_ = 0;
	free_obj_count_ = 0;
	total_obj_count_ = 0;

	reserve(count);
	name_ = typeid(Obj).name();
	DebugInfo();
}

template<class Obj, class Mutex /*= std::mutex*/>
ObjectPool<Obj, Mutex>::~ObjectPool()
{
	clear();
}

template<class Obj, class Mutex /*= std::mutex*/>
size_t ObjectPool<Obj, Mutex>::TotalObjCount() const
{
	return total_obj_count_;
}

template<class Obj, class Mutex /*= std::mutex*/>
size_t ObjectPool<Obj, Mutex>::FreeObjCount() const
{
	return free_obj_count_;
}

template<class Obj, class Mutex /*= std::mutex*/>
size_t ObjectPool<Obj, Mutex>::UseObjCount() const
{
	return use_obj_count_;
}

template<class Obj, class Mutex /*= std::mutex*/>
void ObjectPool<Obj, Mutex>::reserve(int count)
{
	std::lock_guard<Mutex> lock(mutex_);
	obj_vec_.reserve(count);
}

template<class Obj, class Mutex /*= std::mutex*/>
bool ObjectPool<Obj, Mutex>::empty() const
{
	std::lock_guard<Mutex> lock(mutex_);
	return obj_vec_.empty();
}

template<class Obj, class Mutex /*= std::mutex*/>
void ObjectPool<Obj, Mutex>::resize(int initCount)
{
	std::lock_guard<Mutex> lock(mutex_);
	initCount = initCount > 0 ? initCount : E_DEFAULT::DEFAULT_POOL_OBJ_COUNT;
	for (int i = 0; i < initCount; ++i)
	{
		ObjectPlus *p = create();
		obj_vec_.emplace_back(p);
		use_obj_map_[(size_t)(p->obj)] = p;
		free_obj_count_++;
		total_obj_count_++;
	}
}

template<class Obj, class Mutex /*= std::mutex*/>
void ObjectPool<Obj, Mutex>::clear()
{
	std::lock_guard<Mutex> lock(mutex_);
	ObjectPlus *obj = nullptr;
	while (obj_vec_.empty() == false)
	{
		obj = obj_vec_.back();
		obj_vec_.pop_back();
		auto iter = use_obj_map_.find((size_t)(obj->obj));
		if (iter != use_obj_map_.end())
			use_obj_map_.erase(iter);
		SAFE_DELETE(obj->obj);
		SAFE_DELETE(obj);
	}

	use_obj_count_ = 0;
	free_obj_count_ = 0;
	total_obj_count_ = 0;
	UseObjMap().swap(use_obj_map_);
	ObjVec().swap(obj_vec_);
}

template<class Obj, class Mutex>
void ObjectPool<Obj, Mutex>::push(Obj *obj)
{
	std::lock_guard<Mutex> lock(mutex_);
	obj->reset();
	
	auto iter = use_obj_map_.find((size_t)(obj));
	if (iter == use_obj_map_.end())
	{
		ObjectPlus *p = create(obj);
		p->is_use = false;
		use_obj_map_[(size_t)(obj)] = p;
		obj_vec_.push_back(p);
		total_obj_count_++;
	}
	else
	{
		iter->second->is_use = false;
		obj_vec_.push_back(iter->second);
	}
	free_obj_count_++;
	use_obj_count_--;
}

template<class Obj, class Mutex>
Obj* ObjectPool<Obj, Mutex>::pop()
{
	std::lock_guard<Mutex> lock(mutex_);

	ObjectPlus *tmp = nullptr;
	if (obj_vec_.empty())
	{
		tmp = create();
	}
	else
	{
		tmp = obj_vec_.back();
		obj_vec_.pop_back();
		auto iter = use_obj_map_.find((size_t)(tmp->obj));
		if (iter != use_obj_map_.end())
			use_obj_map_.erase(iter);
	}
	
	tmp->is_use = true;
	free_obj_count_--;
	use_obj_count_++;
	return tmp->obj;
}

