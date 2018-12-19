#pragma once

#include <list>

template<class Obj, class Mutex>
class TmpList
{
public:
	TmpList() = default;
	virtual ~TmpList() = default;

	virtual void push_back(Obj *o);
	virtual Obj* pop_back();
	virtual Obj* pop_front();
	virtual bool empty();
	virtual size_t size();
private:
	std::list<Obj*> l_;
	Mutex m_;
};

template<class Obj, class Mutex>
size_t TmpList<Obj, Mutex>::size()
{
	return l_.size();
}

template<class Obj, class Mutex>
Obj* TmpList<Obj, Mutex>::pop_front()
{
	std::lock_guard<Mutex> lock(m_);
	if (l_.empty())
		return nullptr;
	Obj *o = l_.front();
	l_.pop_front();
	return o;
}

template<class Obj, class Mutex>
bool TmpList<Obj, Mutex>::empty()
{
	std::lock_guard<Mutex> lock(m_);
	return l_.empty();
}

template<class Obj, class Mutex>
Obj* TmpList<Obj, Mutex>::pop_back()
{
	std::lock_guard<Mutex> lock(m_);
	if(l_.empty())
		return nullptr;
	Obj *o = l_.back();
	l_.pop_back();
	return o;
}

template<class Obj, class Mutex>
void TmpList<Obj, Mutex>::push_back(Obj *o)
{
	JUDGE_RETURN(o == nullptr, );
	{
		std::lock_guard<Mutex> lock(m_);
		l_.emplace_back(o);
	}
}


