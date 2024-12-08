#pragma once
#include <stdexcept>
#include <initializer_list> 
#include <iostream>

template <class T>
class ForwardList {
public:
    ForwardList(std::size_t size = 0);
    ForwardList(std::size_t size, T filler);
    bool empty();
    T& front();
private:
    struct Node {
        T value;
        Node* next;
    };

    Node* head = nullptr;
    std::size_t size;
};
template<class T>
ForwardList<T>::ForwardList(std::size_t size) : size(size) {
    Node** current = &head;
    for (std::size_t i = 0; i < size; ++i) {
        *current = new Node();
        current = &((*current)->next);
    }
}

template<class T>
ForwardList<T>::ForwardList(std::size_t size, T filler) : size(size) {
    Node** current = &head;
    for (std::size_t i = 0; i < size; ++i) {
        *current = new Node();
        (*current)->value = filler;
        current = &((*current)->next);
    }
}


template<class T>
bool ForwardList<T>::empty() {
    return size == 0;
}
template<class T>
T& ForwardList<T>::front() {
    return head->value;
}
