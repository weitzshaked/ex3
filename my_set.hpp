#ifndef EX3_MY_SET_HPP
#define EX3_MY_SET_HPP

#include "my_set.h"

template<class T>
std::shared_ptr<Node> my_set<T>::_findMinimum(const std::shared_ptr<Node> &root)
{
    while (root->getLeft())
    {
        root = root->getLeft();
    }
    return root;
//    std::shared_ptr<my_set<T>::Node> prev, cur = root;
//    if(root == nullptr)
//    {
//        return nullptr;
//    }
//    while (cur->getLeft()!= nullptr)
//    {
//        prev = cur;
//        cur = cur->getLeft();
//    }
//    return prev;
}

template<class T>
std::shared_ptr<Node> my_set<T>::_findMaximum(const std::shared_ptr<Node> &root)
{
    while (root->getRight())
    {
        root = root->getRight();
    }
    return root;
//    std::shared_ptr<my_set<T>::Node> prev, cur = root;
//    if(root == nullptr)
//    {
//        return nullptr;
//    }
//    while (cur->getRight() != nullptr)
//    {
//        prev = cur;
//        cur = cur->getRight();
//    }
//    return prev;
}

template<class T>
std::shared_ptr<my_set<T>::Node>
my_set<T>::treeIterator::next(const std::shared_ptr<my_set<T>::Node> &node)
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
    std::shared_ptr<Node> cur = node.get();
    while (next != nullptr && cur == next->getRight())
    {
        cur = next;
        next = next->getParent();
    }
    return next;
}

template<class T>
std::shared_ptr<my_set<T>::Node>
my_set<T>::treeIterator::prev(const std::shared_ptr<my_set<T>::Node> &node)
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
    std::shared_ptr<Node> cur = node.get();
    while (next != nullptr && cur == next->getLeft())
    {
        cur = next;
        next = next->getParent();
    }
    return next;
}

template<class T>
typename my_set<T>::const_iterator my_set<T>::find(const value_type &val) const
{
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

    if (cur->getData() == val)
    {
        return treeIterator(cur);
    }

    return treeIterator(nullptr);
}

template<class T>
std::pair<std::shared_ptr<my_set<T>::Node>, bool>
my_set<T>::eraseHelp(std::shared_ptr<my_set<T>::Node> cur, const_reference val)
{
    if (cur == nullptr) {return std::make_pair(nullptr, false);}

    if (val < cur->getData())
    {
        std::pair<std::shared_ptr<Node>, bool> pair = eraseHelp(cur->getLeft(), val);
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
        std::shared_ptr<my_set<T>::Node> parent = cur->getParent();
        if (cur-> getRight() == nullptr && cur->getLeft() == nullptr)
        {
            return std::make_pair(nullptr, true);
        }
        if (cur->getRight() == nullptr)
        {
            std::shared_ptr<my_set<T>::Node> temp = cur->getLeft();
        }
        if (cur->getLeft() == nullptr)
        {
            std::shared_ptr<my_set<T>::Node> temp = cur->getRight();
        }
        else
        {
            std::shared_ptr<my_set<T>::Node> temp = _findMinimum(cur->getRight());
            cur->setData(temp->getData());
            cur->setRight(eraseHelp(cur->getRight(), temp->getData()).first);
            return std::make_pair(cur, true);
        }
        if (cur != nullptr)
        {
            cur->setParent(parent);
        }
        return std::make_pair(cur, true);
    }
};


template<class T>
std::size_t my_set<T>::erase(const value_type &val)
{
    if(eraseHelp(_head,val).second)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

template<class T>
typename std::pair<my_set<T>::const_iterator, bool> my_set<T>::insert(const value_type &val)
{
    std::shared_ptr<Node> prev, cur = _head;

    while (cur != nullptr)
    {
        if (val > cur->getData())
        {
            prev = cur;
            cur = cur->getRight();
        }
        if (val < cur->getData())
        {
            prev = cur;
            cur = cur->getLeft();
        }
        if (val == cur->getData())
        {
            break;
        }
    }

    if (cur != nullptr)
    {
        return std::pair<my_set<T>::const_iterator, bool>(treeIterator(prev), false);
    }

    std::shared_ptr<Node> node = std::make_shared(Node(val));
    node->setParent(prev);
    if (prev->getLeft() != nullptr)
    {
        prev->setRight(node);
    }
    else
    {
        prev->setLeft(node);
    }

    return std::pair<my_set<T>::const_iterator, bool>(treeIterator(node), true);
}

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

template<class T>
template<class InputIt>
my_set<T>::my_set(InputIt begin, InputIt end)
{
    _size =0;
    for(InputIt it = begin(); it != end(); it++)
    {
        insert(*it);
        _size++;
    }
}

template<class T>
void my_set<T>::erase(my_set<T>::const_iterator first,my_set<T>::const_iterator last)
{
    for(my_set<T>::const_iterator it=first; it!= last; it++)
    {
        erase(*it);
    }
}

template <class T>
template<class InputIt>
void my_set<T>::insert(InputIt first, InputIt last)
{
    for(InputIt it=first; it!= last; it++)
    {
        insert(*it);
    }
}
template <class T>
void my_set<T>::clearNode(std::shared_ptr<Node> cur)
{
    std::shared_ptr<my_set<T>::Node> parent = cur->getParent();
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

template <class T>
void my_set<T>::clearHelp(std::shared_ptr<Node> cur) noexcept
{
    if(cur == nullptr)
    {
        return;
    }
    clearHelp(cur->getRight());
    clearHelp(cur->getLeft());
    clearNode(cur);
}

template <class T>
void my_set<T>::clear()
{
    clearHelp(_head);
    _size=0;
    _head = nullptr;
}

template <class T>
typename my_set<T>::const_iterator my_set<T>::erase(my_set<T>::const_iterator pos)
{

}

template <class T>
typename my_set<T>::const_iterator my_set::insert(my_set::const_iterator hint, const value_type &value)
{
    if((*hint)->getData() == value)
    {

    }
}


#endif //EX3_MY_SET_HPP
