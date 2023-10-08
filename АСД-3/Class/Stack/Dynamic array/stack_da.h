#ifndef STACK_DA_H
#define STACK_DA_H

class stack_da {
private:
    int* data_;       // Динамічний масив для зберігання елементів
    int capacity_;    // Розмір масиву
    int top_index_;    // Індекс вершини стеку

    public:
    stack_da(int initial_capacity = 10);
    ~stack_da();

    void push(int value);
    void pop();
    int top() const;
    int size() const;
    void clear();
};

#endif // STACK_DA_H

