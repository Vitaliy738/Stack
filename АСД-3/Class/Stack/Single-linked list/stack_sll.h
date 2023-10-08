#ifndef STACK_SLL_H
#define STACK_SLL_H

template <typename T>
class node {
public:
    T data;       // Data of the node
    node* next;   // Pointer to the next node

    // Constructor for creating a node
    node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class stack_sll {
private:
    node<T>* top_node; // Pointer to the top node

public:
    stack_sll(); 
    ~stack_sll();

    // Adding a new element to the stack
    void push(T value);

    // Removing an element from the stack
    void pop();

    // Reading an element from the top of the stack
    T top() const;

    // Check if the stack is empty
    bool is_empty() const;

    // Clearing the stack
    void clear();           

    // List copy operation
    stack_sll(const stack_sll& other_stack);

    // Overloading the '+' operator
    stack_sll operator+(const stack_sll& other_stack) const;

    // Overloading the '*' operator
    stack_sll operator*(int factor) const;                   
};

#endif // STACK_SLL_H
