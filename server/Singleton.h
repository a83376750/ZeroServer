#pragma once

template<class CObject>
class Singleton
{
private:
	Singleton(void);
	~Singleton(void);
public:
	static CObject *instance(void);
	static void destroy(void);

private:
	static Singleton<CObject> *singleton_;
	CObject instance_;
};

template<class CObject>
inline Singleton<CObject>::Singleton(void)
{ /*NULL*/
}

template<class CObject>
inline Singleton<CObject>::~Singleton(void)
{ /*NULL*/
}

template<class CObject>
Singleton<CObject> *Singleton<CObject>::singleton_ = 0;

template<class CObject>
inline CObject *Singleton<CObject>::instance(void)
{
	if (Singleton<CObject>::singleton_ == 0)
		Singleton<CObject>::singleton_ = new Singleton<CObject>();

	return &(Singleton<CObject>::singleton_->instance_);
}

template<class CObject>
void Singleton<CObject>::destroy(void)
{
	if (Singleton<CObject>::singleton_ != 0)
		delete Singleton<CObject>::singleton_;
	Singleton<CObject>::singleton_ = 0;
}