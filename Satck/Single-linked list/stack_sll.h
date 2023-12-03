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

    void push(T value);
    void pop();
    T top() const;
    bool is_empty() const;
    void clear();

    stack_sll(const stack_sll& other_stack);
    stack_sll operator+(const stack_sll& other_stack) const;
};

#endif // STACK_SLL_H
