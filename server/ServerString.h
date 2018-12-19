#pragma once

class SString
{
public:
	SString();
	SString(const SString &s);
	SString(const char *s);
	virtual ~SString();
	
	void swap(SString &s);
	bool copy(const char *s);
	bool resize(size_t size);
	void append(const char *s);
	size_t size()const;

	SString& operator=(const char *s);
	SString& operator=(const SString &s);
	SString& operator+=(const char *s);

	const char* c_str()const;

	static size_t calSize(const SString &s);
	static size_t calSize(const char *s);
	static char* strcpy(char *source, const char *target);
	static char* strcat(char *source, const char *target);
private:
	char *str_;
	size_t size_;
};

SString::SString()
{
	str_ = new char[1];
	*str_ = '\0';
	size_ = 0;
}

SString::SString(const SString &s)
{
	copy(s.str_);
}

SString::SString(const char *s)
{
	copy(s);
}

SString::~SString()
{
	delete []str_;
}

void SString::swap(SString &s)
{
	char *tmp = nullptr;
	tmp = s.str_;
	s.str_ = str_;
	str_ = tmp;

	size_t size = s.size_;
	s.size_ = size_;
	size_ = size;
}

bool SString::copy(const char *s)
{
	size_t size = SString::calSize(s);
	if (size <= 0)
		return false;
	resize(size);
	return SString::strcpy(str_, s) != nullptr;
}

bool SString::resize(size_t size)
{
	if (size <= 0)
		return false;

	if (size_ == size)
		return true;

	delete[]str_;
	str_ = new char[size + 1];

	if (str_ == nullptr)
		return false;

	size_ = size;
	return true;
}

void SString::append(const char *s)
{
	this->operator+=(s);
}

size_t SString::size() const
{
	return size_;
}

SString& SString::operator=(const char *s)
{
	copy(s);
	return *this;
}

SString& SString::operator+=(const char *s)
{
	size_t size = calSize(s);
	if (size > 0)
	{
		size_t len = size_ + size + 1;
		char *s_tmp = new char[len];
		*s_tmp = '\0';
		SString::strcpy(s_tmp, str_);
		SString::strcat(s_tmp, s);

		delete[]str_;
		str_ = s_tmp;
	}
	return *this;
}

const char* SString::c_str() const
{
	return str_;
}

size_t SString::calSize(const char *s)
{
	if (s == nullptr)
		return 0;

	size_t size = 0;
	while (*s++ != '\0')
	{
		size++;
	}
	return size;
}

size_t SString::calSize(const SString &s)
{
	return calSize(s.str_);
}

char* SString::strcpy(char *source, const char *target)
{
	if ((source == nullptr) || (target == nullptr))
		return nullptr;
	char *tmp = source;
	while ((*tmp++ = *target++) != '\0');
	return source;
}

char* SString::strcat(char *source, const char *target)
{
	char *tmp = source;
	while (*tmp++ != '\0');
	*tmp--;
	while ((*tmp++ = *target++) != '\0');
	return source;
}

SString& SString::operator=(const SString &s)
{
	return this->operator=(s.c_str());
}
