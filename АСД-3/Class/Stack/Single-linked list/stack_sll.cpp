#include "stack_sll.h"
#include <iostream>

node::node(int value) : data(value), next(nullptr) {}

stack_sll::stack_sll() : top_node(nullptr) {}

stack_sll::~stack_sll() {
    clear();
}

// Adding a new element to the stack
void stack_sll::push(int value) {
    node* new_node = new node(value);
    if (top_node == nullptr) {
        top_node = new_node;
    } else {
        new_node->next = top_node;
        top_node = new_node;
    }
}

// Removing an element from the stack
void stack_sll::pop() {
    if (top_node != nullptr) {
        node* temp = top_node;
        top_node = top_node->next;
        delete temp;
    } else {
        std::cout << "stack_sll is empty. Cannot pop.\n";
    }
}

// Reading an element from the top of the stack
int stack_sll::top() const {
    if (top_node != nullptr) {
        return top_node->data;
    } else {
        std::cout << "stack_sll is empty. Cannot get top element.\n";
        return -1;
    }
}

// Check if the stack is empty
bool stack_sll::is_empty() const {
    return top_node == nullptr;
}

// Clearing the stack
void stack_sll::clear() {
    while (top_node != nullptr) {
        node* temp = top_node;
        top_node = top_node->next;
        delete temp;
    }
}

// List copy operation
stack_sll::stack_sll(const stack_sll& other_stack) {
    top_node = nullptr;

    node* current = other_stack.top_node;
    stack_sll temp_stack;

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
stack_sll stack_sll::operator+(const stack_sll& other_stack) const {
    stack_sll result(*this);
    stack_sll temp_stack(other_stack);

    while (!temp_stack.is_empty()) {
        result.push(temp_stack.top());
        temp_stack.pop();
    }

    return result;
}

// Overloading the '*' operator
stack_sll stack_sll::operator*(int factor) const {
    stack_sll result;

    stack_sll temp_stack(*this);

    for (int i = 0; i < factor; ++i) {
        node* temp_current = temp_stack.top_node;
        while (temp_current != nullptr) {
            result.push(temp_current->data);
            temp_current = temp_current->next;
        }
    }

    return result;
}
