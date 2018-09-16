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

template<class T>
my_set<T>::my_set(const my_set &other)
{
	_size = 0;
	_head = nullptr;
	for(iterator it = other.begin(); it != other.end(); it++)
	{
		insert(*it);
	}
}

template<class T>
const_iterator my_set<T>::find(const value_type &val) const
{
	for(iterator it = this->cbegin(); it != this->cend(); it++)
	{
		if(*it._head.getData() == val)
		{
			return it;
		}
	}
}

template<class T>
template<class inputIt>
my_set<T>::my_set(inputIt begin, inputIt end)
{
	_size =0;
	for(iterator it = begin(); it != end(); it++)
	{
		insert(*it);
		_size++;
	}
}

