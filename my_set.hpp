#ifndef EX3_MY_SET_HPP
#define EX3_MY_SET_HPP

#include "my_set.h"

/**
 * finds minimum valued node in tree
 * @param root
 * @return
 */
template<class T>
std::shared_ptr<typename my_set<T>::Node> my_set<T>::_findMinimum(const std::shared_ptr<typename my_set<T>::Node> &root)
{
    std::shared_ptr<Node> cur = root;
    if(root == nullptr)
    {
        return nullptr;
    }
    while (cur->getLeft()!= nullptr)
    {
        cur = cur->getLeft();
    }
    return cur;
}

/**
 * finds maximum valued node in tree
 * @param root
 * @return
 */
template<class T>
typename std::shared_ptr<typename my_set<T>::Node> my_set<T>::_findMaximum(const std::shared_ptr<typename my_set<T>::Node> &root)
{
    std::shared_ptr<Node> cur = root;
    if(root == nullptr)
    {
        return nullptr;
    }
    while (cur->getRight() != nullptr)
    {
        cur = cur->getRight();
    }
    return cur;
}

/**
 * gets the next node
 * @param node
 * @return
 */
template<class T>
std::shared_ptr<typename my_set<T>::Node>
my_set<T>::treeIterator::next(const std::shared_ptr<typename my_set<T>::Node> &node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (node->getRight() != nullptr)
    {
        return _findMinimum(node->getRight());
    }

    std::shared_ptr<Node> next = node->getParent();
    std::shared_ptr<Node> cur = node;
    while (next != nullptr && cur == next->getRight())
    {
        cur = next;
        next = next->getParent();
    }
    return next;
}

/**
 * gets the previous node
 * @param node
 * @return
 */
template<class T>
std::shared_ptr<typename my_set<T>::Node>
my_set<T>::treeIterator::prev(const std::shared_ptr<typename my_set<T>::Node> &node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (node->getLeft() != nullptr)
    {
        return _findMaximum(node->getLeft());
    }

    std::shared_ptr<Node> next = node->getParent();
    std::shared_ptr<Node> cur = node;
    while (next != nullptr && cur == next->getLeft())
    {
        cur = next;
        next = next->getParent();
    }
    return next;
}

/**
 * fins value in set
 * @param val
 * @return
 */
template<class T>
typename my_set<T>::const_iterator my_set<T>::find(const value_type &val) const
{
    if(_head == nullptr)
    {
        return treeIterator(nullptr);
    }
    std::shared_ptr<Node> cur = _head;

    while (cur != nullptr)
    {
        if (cur->getData() == val)
        {
            break;
        }

        if (val > cur->getData())
        {
            cur = cur->getRight();
        }
        else
        {
            cur = cur->getLeft();
        }
    }

    if (cur != nullptr && cur->getData() == val)
    {
        return treeIterator(cur);
    }

    return treeIterator(nullptr);
}

/**
 * helper function for erase
 * @param cur
 * @param val
 * @return
 */
template<class T>
std::pair<std::shared_ptr<typename my_set<T>::Node>, bool>
my_set<T>::eraseHelp(std::shared_ptr<typename my_set<T>::Node> cur, const_reference val)
{
    if (cur == nullptr) {return std::make_pair(nullptr, false);}

    if (val < cur->getData())
    {
        std::pair<std::shared_ptr<Node>, bool> pair = eraseHelp((cur->getLeft()), val);
        cur->setLeft(pair.first);
        return std::make_pair(cur, pair.second);
    }

    else if (val > cur->getData())
    {
        std::pair<std::shared_ptr<Node>, bool> pair = eraseHelp(cur->getRight(), val);
        cur->setRight(pair.first);
        return std::make_pair(cur, pair.second);
    }

    else
    {
        std::shared_ptr<Node> parent = cur->getParent();
        // 2 children
        if (cur-> getRight() != nullptr && cur->getLeft() != nullptr)
        {
            std::shared_ptr<Node> temp = _findMinimum(cur->getRight());
            cur->setData(temp->getData());
            cur->setRight(eraseHelp(cur->getRight(), temp->getData()).first);
            return std::make_pair(cur, true);
        }
        //0 children
        if (cur-> getRight() == nullptr && cur->getLeft() == nullptr)
        {
            _size--;
            return std::make_pair(nullptr, true);
        }
        //1 child
        if (cur->getRight() == nullptr)
        {
            cur = cur->getLeft();
        }
        else
        {
            cur = cur->getRight();
        }
        if (cur != nullptr)
        {
            cur->setParent(parent);
        }
        _size--;
        return std::make_pair(cur, true);
    }
};

/**
 * erases val from set
 * @param val
 * @return 1 if deleted, 0 otherwise
 */
template<class T>
size_t my_set<T>::erase(const value_type &val)
{
    std::pair<std::shared_ptr<Node> , bool> temp = eraseHelp(_head,val);
    _head = temp.first;
    if(temp.second)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/**
 * insert val to set
 * @param val
 * @return
 */
template<class T>
std::pair<typename my_set<T>::const_iterator, bool> my_set<T>::insert(const value_type &val)
{
    std::shared_ptr<Node> prev, cur = _head;
    int flag = 0;
    if(cur == nullptr)
    {
        _head =  std::make_shared<Node>(Node(val));
        _size++;
        return std::pair<my_set<T>::const_iterator, bool>(treeIterator(_head), true);
    }
    while (cur != nullptr)
    {
        if (val > cur->getData())
        {
            prev = cur;
            cur = cur->getRight();
            flag = 1;
        }
        else if (val < cur->getData())
        {
            prev = cur;
            cur = cur->getLeft();
            flag = 0;
        }
        else if (val == cur->getData())
        {
            return std::pair<my_set<T>::const_iterator, bool>(treeIterator(prev), false);
        }
    }

    std::shared_ptr<Node> node = std::make_shared<Node>(Node(val));
    node->setParent(prev);
    if (flag)
    {
        prev->setRight(node);
    }
    else
    {
        prev->setLeft(node);
    }
    _size++;
    return std::pair<my_set<T>::const_iterator, bool>(treeIterator(node), true);
}


/**
 * insert elements from first to last
 * @tparam InputIt
 * @param first
 * @param last
 */
template <class T>
template<class InputIt>
void my_set<T>::insert(InputIt first, InputIt last)
{
    for(InputIt it=first; it!= last; it++)
    {
        insert(*it);
    }
}

/**
 * insert with hint for position
 * @param hint
 * @param value
 * @return
 */
template <class T>
typename my_set<T>::const_iterator my_set<T>::insert(typename my_set<T>::const_iterator hint, const value_type &value)
{
    std::shared_ptr<Node> node = std::make_shared<Node>(Node(value));
    if(getHead() == nullptr || hint == cend())
    {
        return insert(value).first;
    }
    if(*hint == value)
    {
        return hint;
    }
    my_set<T>::const_iterator prev = --hint;
    if(prev.getPointer() == nullptr)
    {
        return insert(value).first;
    }
    if(*hint>value && *prev<value)
    {
        if(prev.getPointer() == hint.getPointer()->getParent())
        {
            node->setParent(hint.getPointer());
            hint.getPointer()->setLeft(node);
            _size++;
            return treeIterator(node);
        }//todo change?
        else if(prev.getPointer() == hint.getPointer()->getLeft())
        {
            node->setParent(prev.getPointer());
            prev.getPointer()->setRight(node);
            _size++;
            return treeIterator(node);
        }
    }
    return insert(value).first;
}



/**
 * r value insert
 * @param val
 * @return
 */
template <class T>
std::pair<typename my_set<T>::const_iterator, bool> my_set<T>::insert(value_type &&val)
{
    auto temp = std::move(val);
    return insert(temp);
}


/**
 * r value insert with hint for position
 * @param hint
 * @param val
 * @return
 */
template <class T>
typename my_set<T>::const_iterator my_set<T>::insert(typename my_set<T>::const_iterator hint, value_type &&val)
{
    auto temp = std::move(val);
    return insert(hint, temp);
}

/**
 * erases elements between first and last
 * @param first
 * @param last
 */
template<class T>
void my_set<T>::erase(typename my_set<T>::const_iterator first,typename my_set<T>::const_iterator last)
{
    for(my_set<T>::const_iterator it=first; it!= last; it++)
    {
        erase(*it);
    }
}

/**
 * claer node
 * @param cur
 */
template <class T>
void my_set<T>::clearNode(std::shared_ptr<typename my_set<T>::Node> cur) noexcept
{
    std::shared_ptr<Node> parent = cur->getParent();
    if(parent)
    {
        if (parent->getData() > cur->getData())
        {
            parent->setLeft(nullptr);
        }
        else
        {
            parent->setRight(nullptr);
        }
    }
    else if(parent == nullptr && _size == 1)
    {
        _head = nullptr;
    }
    cur->setLeft(nullptr);
    cur->setRight(nullptr);
    _size--;

}

/**
 * helper function for clear
 * @param cur
 */
template <class T>
void my_set<T>::clearHelp(std::shared_ptr<typename my_set<T>::Node> cur) noexcept
{
    if(cur == nullptr)
    {
        return;
    }
    clearHelp(cur->getRight());
    clearHelp(cur->getLeft());
    clearNode(cur);
}

/**
 * claer function
 */
template <class T>
void my_set<T>::clear() noexcept
{
    clearHelp(_head);
    _size=0;
    _head = nullptr;
}

/**
 * erases element at pos
 * @param pos
 * @return
 */
template <class T>
typename my_set<T>::const_iterator my_set<T>::erase(typename my_set<T>::const_iterator pos)
{
    std::shared_ptr<Node> nextNode = treeIterator::next(pos.getPointer());
    std::shared_ptr<Node> parent = pos.getPointer()->getParent();
    if(parent)
    {
        eraseHelp(parent, *pos);
    }
    else
    {
        _head = eraseHelp(pos.getPointer(), *pos).first;
    }
    return  const_iterator(nextNode);
}

/**
 * const iterator to begining of set
 * @return
 */
template <class T>
typename my_set<T>::const_iterator my_set<T>::cbegin() const noexcept
{
    return const_iterator(_findMinimum(_head));
}

/**
 * const iterator to after end of set
 * @return
 */
template <class T>
typename my_set<T>::const_iterator my_set<T>::cend() const noexcept
{
    return ++const_iterator(_findMaximum(_head));
}

/**
 * const reverse iterator to begining of set
 * @return
 */
template <class T>
typename my_set<T>::const_reverse_iterator my_set<T>::crbegin() const noexcept
{
    return const_reverse_iterator(_findMaximum(_head));
}

/**
 * const reverse iterator to after end of set
 * @return
 */
template <class T>
typename my_set<T>::const_reverse_iterator my_set<T>::crend() const noexcept
{
//    return ++const_reverse_iterator(_findMinimum(_head));
    if(!_head)
    {
        return reverse_treeIterator(nullptr);
    }
    std::shared_ptr<Node> cur = _head;
    while (cur->getLeft())
    {
        cur = cur->getLeft();
    }
    return reverse_treeIterator(cur);
}


/**
 * copy constructor
 * @param other
 */
template<class T>
my_set<T>::my_set(const my_set &other)
{
    _size = 0;
    _head = nullptr;
    for (my_set<T>::const_iterator it = other.cbegin(); it != other.cend(); it++)
    {
        insert(*it);
    }
}

/**
 * cunstructor, inserts items from begin to end
 * @tparam inputIt
 * @param begin
 * @param end
 */
template<class T>
template<class InputIt>
my_set<T>::my_set(InputIt begin, InputIt end)
{
    _size =0;
    for(InputIt it = begin; it != end; it++)
    {
        insert(*it);
    }
}

/**
 * move constructor
 * @param other
 */
template<class T>
my_set<T>::my_set(my_set &&other) noexcept
{
    this->swap(other);
}

/**
 * operator=
 * @param other
 * @return
 */
template<class T>
my_set<T> &my_set<T>::operator=(my_set other)
{
    this->swap(other);
    return *this;
}

/**
 * swap function
 * @param other
 */
template <class T>
void my_set<T>::swap(my_set<T> &other)
{
    auto temp = this->_size;
    this->_size = other._size;
    other._size = temp;
    std::swap(this->_head, other._head);
}

/**
 * swaps two sets
 * @tparam K
 * @param first
 * @param second
 */
template <class T>
void swap(my_set<T> &first, my_set<T> &second) noexcept
{
    auto temp = first._size;
    first._size = second._size;
    second._size = temp;
    std::swap(first._head, second._head);
}

#endif //EX3_MY_SET_HPP
