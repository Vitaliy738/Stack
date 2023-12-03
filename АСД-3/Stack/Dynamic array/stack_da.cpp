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

/**
 * @brief Adding a new element to the top of the stack.
 *
 * @param value A value that is added to the stack.
 ***/
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

/**
 * @brief Removing an element from the top of the stack.
 **/
template<typename T>
void stack_da<T>::pop() {
    if (top_index_ >= 0) {
        --top_index_;
    } else {
        // stack_da is empty. Cannot pop.
    }
}

/**
 * @brief Reading an element from the top of the stack.
 *
 * @return An element from the top of the stack.
 * If stack is empty - default value for the type T.
 **/
template<typename T>
T stack_da<T>::top() const {
    if (top_index_ >= 0) {
        return data_[top_index_];
    } else {
        // Stack is empty. Cannot get top element.
        return T(); 
    }
}

/**
 * @return Current number of elements in the stack
 **/
template<typename T>
int stack_da<T>::size() const {
    return top_index_ + 1;
}

/**
 * @brief Clearing the stack
 **/
template<typename T>
void stack_da<T>::clear() {
    top_index_ = -1;
}

/**
 * @brief Check if the stack is empty.
 *
 * @return Boolean value of the stack capacity
 **/
template<typename T>
bool stack_da<T>::is_empty() const
{
    return top_index_ < 0;
}

/**
 * @brief Stack copy operation.
 * Clears the contents of the current stack and copies the contents of another stack to it.
 *
 * @param other_stack Stack to copy
 **/
template <typename T>
stack_da<T>::stack_da(const stack_da& other_stack) : top_index_(-1) {
    clear();
    for (int i = 0; i < other_stack.top_index_; i++)
    {
        push(other_stack[i]);
    }
}

/**
 * @brief Adds the value of another stack to the top of the current stack.
 *
 * @return The result of combining stacks.
 **/
template <typename T>
stack_da<T> stack_da<T>::operator+(const stack_da& other_stack) const {
    stack_da<T> result(*this);

    for(int i = 0; i < other_stack.top_index_; i++)
    {
        result.push(other_stack[i]);
        ++result.top_index_;
    }

    return result;
}