#ifndef EX3_MY_SET_H
#define EX3_MY_SET_H

#include <iostream>
#include <bits/shared_ptr.h>
#include <memory>


template<class T>
class my_set
{
public:
	typedef T value_type;
	typedef value_type &reference;
	typedef const value_type &const_reference;

	class Node
	{
		std::shared_ptr<my_set> _parent;
		std::shared_ptr<my_set> _right;
		std::shared_ptr<my_set> _left;
		value_type _data;

		Node() = default;

		value_type getData()
		{
			return _data;
		}
		Node next(std::shared_ptr<Node> other)
		{
			if(other.get().)
		}

		Node prev(std::shared_ptr<Node> other)
		{

		}
	};

//	typedef const std::bidirectional_iterator_tag iterator;
//	typedef const std::bidirectional_iterator_tag const_iterator;
	typedef std::reverse_iterator<iterator> reverse_iterator;

	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	class treeIterator
	{
		std::shared_ptr<Node> _pointer;

	public:
		explicit treeIterator(std::shared_ptr<Node> current):_pointer(current){};

		treeIterator() = default;

		~treeIterator() = default;

		const std::shared_ptr<Node> &get_pointer() const
		{
			return _pointer;
		}

		treeIterator<T> &operator=(const treeIterator<T> &);

		treeIterator<T> &operator=(treeIterator<T> &&);

		virtual treeIterator operator++()
		{
			_pointer = _pointer.get()->next(_pointer);
			return *this;
		}

		virtual treeIterator operator++(int)
		{
			treeIterator temp = *this;
			_pointer = _pointer.get()->next(_pointer);
			return temp;
		}

		virtual treeIterator operator--()
		{
			_pointer = _pointer.get()->prev(_pointer);
			return *this;
		}

		virtual treeIterator operator--(int)
		{
			treeIterator temp = *this;
			_pointer = _pointer.get()->prev(_pointer);
			return temp;
		}

		reference operator*();

//		T *operator->();
//
//		const T *operator->() const;
//
//		bool operator==(const treeIterator<T> &) const;
//
//		bool operator!=(const treeIterator<T> &) const;

	};

	/**
	 * destructor
	 */
	~my_set()
	{
		clear();
	};

	/**
	 * default constructor
	 */
	my_set() : _head(nullptr), _size(0) {};

	/**
	 * copy constructor
	 * @param other
	 */
	my_set(const my_set &other);

	/**
	 * move constructor
	 * @param other
	 */
	my_set(my_set &&other) noexcept;

	template<class inputIt>
	my_set(inputIt begin, inputIt end);

	my_set &operator=(my_set other);

	bool empty()
	{
		return size() == 0;
	}

	size_t size()
	{
		return _size;
	}

	constexpr void swap(T &a, T &b) noexcept;


	template<class InputIt>
	void insert(InputIt first, InputIt last);

	std::pair<const_iterator, bool> insert(const value_type &val);

	iterator insert(const_iterator hint, const value_type &value);

	void clear() noexcept;

	const_iterator find(const value_type &val) const;

	const_iterator cbegin() const noexcept;

	const_iterator cend() const noexcept;

	const_reverse_iterator crbegin() const noexcept;

	const_reverse_iterator crend() const noexcept;

	friend void swap(my_set &first, my_set &second) noexcept;

	iterator erase(const_iterator pos);

	void erase(iterator first, iterator last);

private:
	std::weak_ptr<Node> _head;
	size_t _size;
};


#endif //EX3_MY_SET_H
