#include "stack_sll.h"

template <typename T>
stack_sll<T>::stack_sll() : top_node(nullptr) {}

template <typename T>
stack_sll<T>::~stack_sll() {
    clear();
}

/**
 * @brief Adding a new element to the top of the stack.
 *
 * @param value A value that is added to the stack.
 *
 ***/
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

/**
 * @brief Removing an element from the top of the stack.
 **/
template <typename T>
void stack_sll<T>::pop() {
    if (top_node != nullptr) {
        node<T>* temp = top_node;
        top_node = top_node->next;
        delete temp;
    } else {
        // Stack is empty. Cannot pop.
    }
}

/**
 * @brief Reading an element from the top of the stack.
 *
 * @return An element from the top of the stack.
 * If stack is empty - default value for the type T.
 **/
template <typename T>
T stack_sll<T>::top() const {
    if (top_node != nullptr) {
        return top_node->data;
    } else {
        // Stack is empty. Cannot get top element.
        return T(); 
    }
}

/**
 * @brief Check if the stack is empty.
 *
 * @return Boolean value of the stack capacity
 **/
template <typename T>
bool stack_sll<T>::is_empty() const {
    return top_node == nullptr;
}

/**
 * @brief Clearing the stack
 **/
template <typename T>
void stack_sll<T>::clear() {
    while (top_node != nullptr) {
        node<T>* temp = top_node;
        top_node = top_node->next;
        delete temp;
    }
}

/**
 * @brief Stack copy operation.
 * Clears the contents of the current stack and copies the contents of another stack to it.
 *
 * @param other_stack Stack to copy
 **/
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

/**
 * @brief Adds the value of another stack to the top of the current stack.
 *
 * @return The result of combining stacks.
 **/
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