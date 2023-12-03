#ifndef STACK_DA_H
#define STACK_DA_H

template <typename T>
class stack_da {
private:
    T* data_;         // Dynamic array for storing elements
    int capacity_;    // Array size
    int top_index_;   // Stack top index

public:
    stack_da(int initial_capacity = 1);
    ~stack_da();

    void push(T value);
    void pop();
    T top() const;
    int size() const;
    bool is_empty() const;
    void clear();

    stack_da(const stack_da& other_stack);
    stack_da operator+(const stack_da& other_stack) const;
};

#endif // STACK_DA_H

