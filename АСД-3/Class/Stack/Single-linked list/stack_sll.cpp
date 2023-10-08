#include "stack_sll.h"
#include <iostream>

template <typename T>
stack_sll<T>::stack_sll() : top_node(nullptr) {}

template <typename T>
stack_sll<T>::~stack_sll() {
    clear();
}

// Adding a new element to the stack
template <typename T>
void stack_sll<T>::push(T value) {
    node<T>* new_node = new node<T>(value);
    if (top_node == nullptr) {
        top_node = new_node;
    } else {
        new_node->next = top_node;
        top_node = new_node;
    }
}

// Removing an element from the stack
template <typename T>
void stack_sll<T>::pop() {
    if (top_node != nullptr) {
        node<T>* temp = top_node;
        top_node = top_node->next;
        delete temp;
    } else {
        std::cout << "Stack is empty. Cannot pop.\n";
    }
}

// Reading an element from the top of the stack
template <typename T>
T stack_sll<T>::top() const {
    if (top_node != nullptr) {
        return top_node->data;
    } else {
        std::cout << "Stack is empty. Cannot get top element.\n";
        return T(); 
    }
}

// Check if the stack is empty
template <typename T>
bool stack_sll<T>::is_empty() const {
    return top_node == nullptr;
}

// Clearing the stack
template <typename T>
void stack_sll<T>::clear() {
    while (top_node != nullptr) {
        node<T>* temp = top_node;
        top_node = top_node->next;
        delete temp;
    }
}

// List copy operation
template <typename T>
stack_sll<T>::stack_sll(const stack_sll& other_stack) : top_node(nullptr) {
    node<T>* current = other_stack.top_node;
    stack_sll<T> temp_stack;

    while (current != nullptr) {
        temp_stack.push(current->data);
        current = current->next;
    }

    while (!temp_stack.is_empty()) {
        push(temp_stack.top());
        temp_stack.pop();
    }
}

// Overloading the '+' operator
template <typename T>
stack_sll<T> stack_sll<T>::operator+(const stack_sll& other_stack) const {
    stack_sll<T> result(*this);
    stack_sll<T> temp_stack(other_stack);

    while (!temp_stack.is_empty()) {
        result.push(temp_stack.top());
        temp_stack.pop();
    }

    return result;
}

// Overloading the '*' operator
template <typename T>
stack_sll<T> stack_sll<T>::operator*(int factor) const {
    stack_sll<T> result;

    stack_sll<T> temp_stack(*this);

    for (int i = 0; i < factor; ++i) {
        node<T>* temp_current = temp_stack.top_node;
        while (temp_current != nullptr) {
            result.push(temp_current->data);
            temp_current = temp_current->next;
        }
    }

    return result;
}
