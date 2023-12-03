#include "stack_da.h"
#include <iostream>

template<typename T>
stack_da<T>::stack_da(int initial_capacity) {
    capacity_ = initial_capacity;
    data_ = new T[capacity_];
    top_index_ = -1;
}

template<typename T>
stack_da<T>::~stack_da() {
    delete[] data_;
}

// Adding a new element to the stack
template<typename T>
void stack_da<T>::push(T value) {
    if (top_index_ == capacity_ - 1) {
        int new_capacity = capacity_ * 2;
        T* new_data = new T[new_capacity];

        for (int i = 0; i <= top_index_; ++i) {
            new_data[i] = data_[i];
        }

        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }

    data_[++top_index_] = value;
}

// Removing an element from the stack
template<typename T>
void stack_da<T>::pop() {
    if (top_index_ >= 0) {
        --top_index_;
    } else {
        std::cout << "stack_da is empty. Cannot pop.\n";
    }
}

// Reading an element from the top of the stack
template<typename T>
T stack_da<T>::top() const {
    if (top_index_ >= 0) {
        return data_[top_index_];
    } else {
        std::cout << "stack_da is empty. Cannot get top element.\n";
        return T();  // Default value for the type T (assuming T has a default constructor)
    }
}

// Current number of elements in the stack
template<typename T>
int stack_da<T>::size() const {
    return top_index_ + 1;
}


// Clearing the stack
template<typename T>
void stack_da<T>::clear() {
    top_index_ = -1;
}
