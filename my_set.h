#ifndef EX3_MY_SET_H
#define EX3_MY_SET_H

#include <iostream>
#include <memory>
#include <iomanip>

/**
 * class representing a logial set
 * @tparam T
 */
template<class T>
class my_set
{
private:
	/**
	 * Node class
	 */
	class Node
	{
	private:
		std::weak_ptr<Node> _parent;
		std::shared_ptr<Node> _right, _left;
		T _data;

	public:
		/**
		 * gets data
		 * @return
		 */
		const T &getData() const { return _data; }

		/**
		 * sets data
		 * @param data
		 */
		void setData(const T &data) { _data = data; }

		/**
		 * sets parent
		 * @param parent
		 */
		void setParent(std::weak_ptr<Node> parent) { _parent = parent; }

		/**
		 * sets right son
		 * @param right
		 */
		void setRight(std::shared_ptr<Node> right) { _right = right; }

		/**
		 * sets left son
		 * @param left
		 */
		void setLeft(std::shared_ptr<Node> left) { _left = left; }

		/**
		 * constructor
		 * @param data
		 */
		explicit Node(T data) : _data(data) {};

		/**
		 * get parent
		 * @return
		 */
		std::shared_ptr<Node> getParent() { return _parent.lock(); }

		/**
		 * get right son
		 * @return
		 */
		std::shared_ptr<Node> getRight() { return _right; }

		/**
		 * get left son
		 * @return
		 */
		std::shared_ptr<Node> getLeft() { return _left; }

		/**
		 * operator =
		 * @param other
		 * @return
		 */
		Node &operator=(const Node &other)
		{
			_parent = other._parent;
			_right = other._right;
			_left = other._left;
			_data = other._data;
		}
	};

	std::shared_ptr<Node> _head;
	std::size_t _size;

	/**
	 * finds minimum valued node in tree
	 * @param root
	 * @return
	 */
	static std::shared_ptr<Node> _findMinimum(const std::shared_ptr<Node> &root);

	/**
	 * finds maximum valued node in tree
	 * @param root
	 * @return
	 */
	static std::shared_ptr<Node> _findMaximum(const std::shared_ptr<Node> &root);

public:
	/**
	 * tree iterator class
	 */
	class treeIterator
	{
	protected:
		std::shared_ptr<Node> _pointer;

	public:
		/**
		 * constructor
		 * @param current
		 */
		explicit treeIterator(std::shared_ptr<Node> current) : _pointer(current) {};

		/**
		 * default constructor
		 */
		treeIterator() = default;

		/**
		 * destructor
		 */
		~treeIterator() = default;

		/**
		 * gets pointer
		 * @return
		 */
		std::shared_ptr<Node> getPointer() { return _pointer; }

		/**
		 * operator ++
		 * @return
		 */
		virtual treeIterator operator++()
		{
			_pointer = next(_pointer);
			return *this;
		}

		/**
		 * operator ++(int)
		 * @return
		 */
		virtual const treeIterator operator++(int)
		{
			treeIterator temp = *this;
			_pointer = next(_pointer);
			return temp;
		}

		/**
		 * operator --
		 * @return
		 */
		virtual treeIterator operator--()
		{
			_pointer = prev(_pointer);
			return *this;
		}

		/**
		 * operator --(int)
		 * @return
		 */
		virtual const treeIterator operator--(int)
		{
			treeIterator temp = *this;
			_pointer = prev(_pointer);
			return temp;
		}

		/**
		 * operator *
		 * @return
		 */
		const T &operator*() { return _pointer.get()->getData(); };

		/**
		 * operator ->
		 * @return
		 */
		T *operator->()
		{
			if (_pointer) { return &_pointer.get()->getData(); }
			return nullptr;
		};

		/**
		 * operator ==
		 * @param other
		 * @return
		 */
		bool operator==(const treeIterator &other) const { return _pointer == other._pointer; };

		/**
		 * operator !=
		 * @param other
		 * @return
		 */
		bool operator!=(const treeIterator &other) const { return _pointer != other._pointer; }

		/**
		 * gets the next node
		 * @param node
		 * @return
		 */
		static std::shared_ptr<Node> next(const std::shared_ptr<Node> &node);

		/**
		 * gets the previous node
		 * @param node
		 * @return
		 */
		static std::shared_ptr<Node> prev(const std::shared_ptr<Node> &node);
	};

	/**
	 * class of a reverse tree iterator
	 */
	class reverse_treeIterator : public treeIterator
	{
	public:
		/**
		 * constructor
		 * @param current
		 */
		explicit reverse_treeIterator(std::shared_ptr<Node> current) : treeIterator(current) {};

		/**
		 * reverse --
		 * @return
		 */
		virtual treeIterator operator--()
		{
			this->_pointer = this->next(this->_pointer);
			return *this;
		}

		/**
		 * reverse --(int)
		 * @return
		 */
		virtual const treeIterator operator--(int)
		{
			treeIterator temp = *this;
			this->_pointer = this->next(this->_pointer);
			return temp;
		}

		/**
		 * reverse ++
		 * @return
		 */
		virtual treeIterator operator++()
		{
			this->_pointer = this->prev(this->_pointer);
			return *this;
		}

		/**
		* reverse ++(int)
		* @return
		*/
		virtual const treeIterator operator++(int)
		{
			treeIterator temp = *this;
			this->_pointer = this->prev(this->_pointer);
			return temp;
		}

	};


	typedef T value_type;
	typedef const value_type &const_reference;
	typedef treeIterator const_iterator;
	typedef reverse_treeIterator const_reverse_iterator;


	/**
	 * destructor
	 */
	~my_set() { clear(); };

	//constructors

	/**
	 * default constructor
	 */
	my_set() : _size(0) {};

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

	/**
	 * cunstructor, inserts items from begin to end
	 * @tparam inputIt
	 * @param begin
	 * @param end
	 */
	template<class inputIt>
	my_set(inputIt begin, inputIt end);

	//operators

	/**
	 * operator=
	 * @param other
	 * @return
	 */
	my_set &operator=(my_set other);

	//methods

	/**
	 * @return true if the set is empty
	 */
	bool empty() { return size() == 0; }

	/**
	 *
	 * @return size of set
	 */
	size_t size() { return _size; }


	//insert


	/**
	 * insert elements from first to last
	 * @tparam InputIt
	 * @param first
	 * @param last
	 */
	template<class InputIt>
	void insert(InputIt first, InputIt last);

	/**
	 * insert val to set
	 * @param val
	 * @return
	 */
	std::pair<const_iterator, bool> insert(const value_type &val);

	/**
	 * r value insert
	 * @param val
	 * @return
	 */
	std::pair<const_iterator, bool> insert(value_type &&val);

	/**
	 * insert with hint for position
	 * @param hint
	 * @param value
	 * @return
	 */
	const_iterator insert(const_iterator hint, const value_type &value);

	/**
	 * r value insert with hint for position
	 * @param hint
	 * @param val
	 * @return
	 */
	const_iterator insert(const_iterator hint, value_type &&val);

	/**
	 * claer node
	 * @param cur
	 */
	void clearNode(std::shared_ptr<Node> cur) noexcept;

	/**
	 * helper function for clear
	 * @param cur
	 */
	void clearHelp(std::shared_ptr<Node> cur) noexcept;

	/**
	 * claer function
	 */
	void clear() noexcept;

	/**
	 * fins value in set
	 * @param val
	 * @return
	 */
	const_iterator find(const value_type &val) const;

	/**
	 * const iterator to begining of set
	 * @return
	 */
	const_iterator cbegin() const noexcept;

	/**
	 * const iterator to after end of set
	 * @return
	 */
	const_iterator cend() const noexcept;

	/**
	 * const reverse iterator to begining of set
	 * @return
	 */
	const_reverse_iterator crbegin() const noexcept;

	/**
	 * const reverse iterator to after end of set
	 * @return
	 */
	const_reverse_iterator crend() const noexcept;

	//erase methods

	/**
	 * helper function for erase
	 * @param cur
	 * @param val
	 * @return
	 */
	std::pair<std::shared_ptr<Node>, bool>
	eraseHelp(std::shared_ptr<Node> cur, const_reference val);

	/**
	 * erases element at pos
	 * @param pos
	 * @return
	 */
	const_iterator erase(const_iterator pos);

	/**
	 * erases val from set
	 * @param val
	 * @return 1 if deleted, 0 otherwise
	 */
	std::size_t erase(const value_type &val);

	/**
	 * erases elements between first and last
	 * @param first
	 * @param last
	 */
	void erase(const_iterator first, const_iterator last);

	/**
	 * swaps two sets
	 * @tparam K
	 * @param first
	 * @param second
	 */
	template<class K>
	friend void swap(my_set<K> &first, my_set<K> &second) noexcept;

	/**
	 * swap function
	 * @param other
	 */
	void swap(my_set &other);

	//getters

	/**
	 *
	 * @return head of set
	 */
	std::shared_ptr<Node> getHead() { return _head; };

};

#include "my_set.hpp"

#endif //EX3_MY_SET_H
