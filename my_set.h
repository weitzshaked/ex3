#ifndef EX3_MY_SET_H
#define EX3_MY_SET_H

#include <iostream>
#include <memory>


template<class T>
class my_set
{
private:
    class Node
    {
    private:
        std::weak_ptr<Node> _parent;
        std::shared_ptr<Node> _right, _left;
        T _data;

    public:
        const T &getData() const { return _data; }

        void setData(const T &data) { _data = data; }

        void setParent(std::weak_ptr<Node> parent) { _parent = parent; }

        void setRight(std::shared_ptr<Node> right) { _right = right; }

        void setLeft(std::shared_ptr<Node> left) { _left = left; }

        /**
         * constructor
         * @param data
         */
        explicit Node(T data) : _data(data) {};

        std::shared_ptr<Node> getParent() { return _parent.lock(); }

        std::shared_ptr<Node> getRight() { return _right; }

        std::shared_ptr<Node> getLeft() { return _left; }

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

    static std::shared_ptr<Node> _findMinimum(const std::shared_ptr<Node> &root);

    static std::shared_ptr<Node> _findMaximum(const std::shared_ptr<Node> &root);

public:
    class treeIterator
    {
    protected:
        std::shared_ptr<Node> _pointer;

    public:
        explicit treeIterator(std::shared_ptr<Node> current) : _pointer(current) {};

        treeIterator() = default;

        ~treeIterator() = default;

        std::shared_ptr<Node> getPointer() { return _pointer; }

        virtual treeIterator operator++()
        {
            _pointer = next(_pointer);
            return *this;
        }

        virtual treeIterator operator++(int)
        {
            treeIterator temp = *this;
            _pointer = next(_pointer);
            return temp;
        }

        virtual treeIterator operator--()
        {
            _pointer = prev(_pointer);
            return *this;
        }

        virtual treeIterator operator--(int)
        {
            treeIterator temp = *this;
            _pointer = prev(_pointer);
            return temp;
        }

        const T &operator*()
        { return _pointer.get()->getData(); };

        T *operator->()
        {
            if (_pointer) { return &_pointer.get()->getData(); }
            return nullptr;
        };

        bool operator==(const treeIterator &other) const
        { return _pointer == other._pointer; };

        bool operator!=(const treeIterator &other) const
        { return _pointer != other._pointer; }

        std::shared_ptr<Node> next(const std::shared_ptr<Node> &node);

        std::shared_ptr<Node> prev(const std::shared_ptr<Node> &node);
    };

    class reverse_treeIterator : public treeIterator
    {
    public:
        explicit reverse_treeIterator(std::shared_ptr<Node> current) : treeIterator(current) {};
        virtual treeIterator operator--()
        {
            this->_pointer = this->next(this->_pointer);
            return *this;
        }

        virtual treeIterator operator--(int)
        {
            treeIterator temp = *this;
            this->_pointer = this->next(this->_pointer);
            return temp;
        }

        virtual treeIterator operator++()
        {
            this->_pointer = this->prev(this->_pointer);
            return *this;
        }

        virtual treeIterator operator++(int)
        {
            treeIterator temp = *this;
            this->_pointer = this->prev(this->_pointer);
            return temp;
        }

    };


    typedef T value_type;
    typedef const value_type &const_reference;
    typedef treeIterator const_iterator;
    typedef reverse_treeIterator reverse_iterator;


    /**
     * destructor
     */
    ~my_set()
    { clear(); };

    //constructors

    /**
     * default constructor
     */
    my_set() : _size(0)
    {};

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

    //operators

    my_set &operator=(my_set other);

    //methods

    bool empty() { return size() == 0; }

    size_t size() { return _size; }


    //insert

    template<class InputIt>
    void insert(InputIt first, InputIt last);

    std::pair<const_iterator, bool> insert(const value_type &val);

    std::pair<const_iterator,bool> insert (value_type&& val);

    const_iterator insert(const_iterator hint, const value_type &value);

    const_iterator insert (const_iterator hint, value_type&& val);

    void clearNode(std::shared_ptr<Node> cur) noexcept;

    void clearHelp(std::shared_ptr<Node> cur) noexcept;

    void clear() noexcept;

    const_iterator find(const value_type &val) const;

    const_iterator cbegin() const noexcept;

    const_iterator cend() const noexcept;

    reverse_iterator crbegin() const noexcept;

    reverse_iterator crend() const noexcept;

    //erase methods

    std::pair<std::shared_ptr<Node>, bool>
    eraseHelp(std::shared_ptr<Node> cur, const_reference val);

    const_iterator erase(const_iterator pos);

    std::size_t erase(const value_type &val);

    void erase(const_iterator first, const_iterator last);

    template<class K>
    friend void swap(my_set<K> &first, my_set<K> &second) noexcept;

    void swap(my_set &other) ;

    //getters

    std::shared_ptr<Node> getHead(){ return _head; };

};

#include "my_set.hpp"

#endif //EX3_MY_SET_H
