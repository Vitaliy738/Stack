#include "stack_da.h"
#include <iostream>

stack_da::stack_da(int initial_capacity) {
    capacity_ = initial_capacity;
    data_ = new int[capacity_];
    top_index_ = -1;  // Індекс вершини починається з -1 (порожній стек)
}

stack_da::~stack_da() {
    delete[] data_;  // Звільнення пам'яті при знищенні об'єкта
}

void stack_da::push(int value) {
    // Перевірка на переповнення стеку
    if (top_index_ == capacity_ - 1) {
        // Розширення масиву у рази
        int new_capacity = capacity_ * 2;
        int* new_data = new int[new_capacity];

        // Копіювання елементів у новий масив
        for (int i = 0; i <= top_index_; ++i) {
            new_data[i] = data_[i];
        }

        // Звільнення пам'яті та оновлення посилань
        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }

    // Додавання нового елементу до стеку
    data_[++top_index_] = value;
}

void stack_da::pop() {
    // Перевірка на пустий стек
    if (top_index_ >= 0) {
        // Вилучення елементу з вершини
        --top_index_;
    } else {
        std::cout << "Стек порожній. Неможливо вилучити елемент.\n";
    }
}

int stack_da::top() const {
    // Перевірка на порожній стек
    if (top_index_ >= 0) {
        // Повернення значення з вершини
        return data_[top_index_];
    } else {
        std::cout << "Стек порожній. Неможливо отримати елемент.\n";
        return -1;  // Повертаємо -1 у разі порожнього стеку
    }
}

int stack_da::size() const {
    // Повернення кількості елементів у стеці
    return top_index_ + 1;
}

void stack_da::clear() {
    // Очищення стеку (просто встановлюємо індекс вершини на -1)
    top_index_ = -1;
}
