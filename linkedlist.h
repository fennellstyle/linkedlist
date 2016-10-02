//
// Created by sean on 10/2/16.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <memory>
#include <stdexcept>

template <typename T>
struct Node {
    typedef T value_type;
    Node() : val{}, m_next{nullptr} {}
    Node(T v) : val{v}, m_next{nullptr} {}
    std::shared_ptr<Node<T>> next() { return m_next; }
    const std::shared_ptr<Node<T>> next() const { return m_next; }
    const T get() const { return val;}
    T& get() { return val;}
    std::shared_ptr<Node<T>> setNext(T v) {
        m_next = std::shared_ptr<Node<T>>(new Node<T>(v));
        return m_next;
    }
    std::shared_ptr<Node<T>> operator++() { return m_next; }
private:
    T val;
    std::shared_ptr<Node<T>> m_next;
};

template <typename T>
class LinkedList;

template <typename TNode>
class LinkedListIter {
    friend class LinkedList<typename TNode::value_type>;
    std::shared_ptr<TNode> p;
public:
    LinkedListIter(std::shared_ptr<TNode> p) : p(p) {}
    LinkedListIter(const LinkedListIter& other) : p(other.p) {}
    LinkedListIter& operator=(LinkedListIter other) { std::swap(p, other.p); return *this; }
    void operator++() { p = p->next(); }
    void operator++(int) { p = p->next(); }
    bool operator==(const LinkedListIter& other) { return p == other.p; }
    bool operator!=(const LinkedListIter& other) { return p != other.p; }
    const typename TNode::value_type& operator*() const { return p->get(); }
    typename TNode::value_type& operator*() { return p->get(); }
    LinkedListIter<TNode> operator+(int i)
    {
        LinkedListIter<TNode> iter = *this;
        while (i-- > 0 && iter.p)
        {
            ++iter;
        }
        return iter;
    }

};

template <typename T>
class LinkedList {
public:
    typedef Node<T> node;
    typedef LinkedListIter<node> iterator;
    typedef LinkedListIter<const node> const_iterator;

    LinkedList() : m_size{0}, m_front{nullptr}, m_tail{nullptr} {};
    LinkedList(std::initializer_list<T> initlist) {
        for(auto x: initlist) {
            add(x);
        }
    }
    size_t size() const {
        return m_size;
    }

    const std::shared_ptr<node>head() const {
        if (!m_front)
            throw std::out_of_range("Invalid access.");

        return m_front;
    }

    void add(T val) {
        if (!m_front) {
            m_front = std::shared_ptr<node>(new node(val));
            m_tail = m_front;
            m_size = 1;
        } else {
            m_tail = m_tail->setNext(val);
            m_size++;
        }
    }

    iterator begin() const { return iterator(m_front); }
    iterator end() const { return iterator(m_tail); }

private:
    size_t m_size;
    std::shared_ptr<Node<T>> m_front;
    std::shared_ptr<Node<T>> m_tail;
};

#endif //LINKEDLIST_LINKEDLIST_H
