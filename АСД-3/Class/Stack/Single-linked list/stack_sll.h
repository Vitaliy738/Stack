#ifndef STACK_SLL_H
#define STACK_SLL_H

class node {
public:
    int data;
    node* next;

    node(int value);
};

class stack_sll {
private:
    node* top_node;

public:
    stack_sll();
    ~stack_sll();

    void push(int value);
    void pop();
    int top() const;
    bool is_empty() const;
    void clear();

    // Операція копіювання списку
    stack_sll(const stack_sll& other_stack);

    // Перевантаження оператору '+'
    stack_sll operator+(const stack_sll& other_stack) const;

    // Перевантаження оператору '*'
    stack_sll operator*(int factor) const;
};

#endif // STACK_SLL_H
