#ifndef EX3_MY_SET_H
#define EX3_MY_SET_H

#include <iostream>


template<class T>
class my_set
{
public:
	typedef T value_type;
	typedef T *iterator;
	typedef const T *const_iterator;
	typedef const T &const_reference;

	my_set();

	my_set(const my_set &other);

	my_set(const my_set &&other);

	my_set(iterator begin, iterator end);

	const my_set &operator=(const my_set &other);

	bool empty()
	{
		return size() != 0;
	}

	size_t size();

	constexpr void swap(T &a, T &b) noexcept;

	std::pair<const_iterator, bool> insert(const value_type &val);

	void clear() noexcept;

	const_iterator find(const value_type &val) const;

private:
	class Node
	{
		my_set *right;
		my_set *left;
		T data;
	};
};


#endif //EX3_MY_SET_H
