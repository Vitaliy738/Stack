#include "stack_da.h"
#include <iostream>

stack_da::stack_da(int initial_capacity) {
    capacity_ = initial_capacity;
    data_ = new int[capacity_];
    top_index_ = -1; 
}

stack_da::~stack_da() {
    delete[] data_;  
}

// Adding a new element to the stack
void stack_da::push(int value) {
    if (top_index_ == capacity_ - 1) {
        int new_capacity = capacity_ * 2;
        int* new_data = new int[new_capacity];

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
void stack_da::pop() {
    if (top_index_ >= 0) {
        --top_index_;
    } else {
        std::cout << "stack_sll is empty. Cannot pop.\n";
    }
}

// Reading an element from the top of the stack
int stack_da::top() const {
    if (top_index_ >= 0) {
        return data_[top_index_];
    } else {
        std::cout << "stack_sll is empty. Cannot get top element.\n";
        return -1;  
    }
}

// Current number of elements in the stack
int stack_da::size() const {
    return top_index_ + 1;
}

// Clearing the stack
void stack_da::clear() {
    top_index_ = -1;
}
