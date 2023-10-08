#ifndef STACK_DA_H
#define STACK_DA_H

template <typename T>
class stack_da {
private:
    T* data_;         // Dynamic array for storing elements
    int capacity_;    // Array size
    int top_index_;   // Stack top index

public:
    stack_da(int initial_capacity = 10);
    ~stack_da();

    // Adding a new element to the stack
    void push(T value);

    // Removing an element from the stack
    void pop();

    // Reading an element from the top of the stack
    T top() const;

    // Current number of elements in the stack
    int size() const;

    // Clearing the stack
    void clear();         
};

#endif // STACK_DA_H

