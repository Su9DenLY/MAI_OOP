#pragma once
#include <exception>
#include <iostream>
#include <memory>

#include "allocator.hpp"

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node() = default;
    Node(const T& value) : data(value), next(nullptr) {}
    ~Node() = default;
};
template <typename T, typename Allocator = std::allocator<T>>
class My_stack {
public:
    using value_type = T;
    using allocator_type = Allocator;
    using size_type = std::size_t;

public:
    class iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        iterator(Node<T>* node) : currentNode(node) {}

        iterator& operator++() {
            if (currentNode != nullptr) {
                currentNode = currentNode->next;
            }
            return *this;
        }

        iterator operator++(int) {
            iterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const iterator& other) const {
            return currentNode == other.currentNode;
        }

        bool operator!=(const iterator& other) const {
            return !(*this == other);
        }

        reference operator*() const {
            return currentNode->data;
        }

        pointer operator->() const {
            return currentNode->data;
        }

    private:
        Node<T>* currentNode;
    };

    using const_iterator = iterator;

    My_stack() : _head(nullptr), _size(0) {}

    void push(const value_type& value) {
        Node<T>* newNode = _allocator.allocate(1);
        newNode->data = value;
        newNode->next = _head;
        _head = newNode;
        ++_size;
    }

    void pop() {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        Node<T>* temp = _head;
        _head = _head->next;
        _allocator.deallocate(temp, 1);
        --_size;
    }

    value_type& top() {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return _head->data;
    }

    const value_type& top() const {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return _head->data;
    }
    bool empty() const {
        return _size == 0;
    }

    size_type size() const {
        return _size;
    }

    iterator begin() {
        return iterator(_head);
    }

    iterator end() {
        return iterator(nullptr);
    }

    const_iterator cbegin() const {
        return const_iterator(_head);
    }

    const_iterator cend() const {
        return const_iterator(nullptr);
    }

private:
    Node<T>* _head;
    size_type _size;
    allocator_type _allocator;
};