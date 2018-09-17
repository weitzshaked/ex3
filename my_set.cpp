#include "my_set.h"

template<class T>
my_set<T>::my_set(my_set &&other) noexcept
{
//	_string = other._string;
//	other._string = nullptr;
//	_length = other._length;

}

template<class T>
my_set<T> &my_set<T>::operator=(my_set other)
{
	swap(*this, other);
	return *this;
}




