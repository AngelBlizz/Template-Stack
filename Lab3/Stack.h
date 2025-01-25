#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

template <typename T>
class Stack {
private:
    T* data;        // Указатель на динамический массив
    int capacity;   // Вместимость стека
    int top;        // Индекс верхнего элемента стека

public:
    // Конструктор
    Stack(int capacity = 10);

    // Деструктор
    ~Stack();

    // Копирующий конструктор
    Stack(const Stack& other);

    // Оператор присваивания
    Stack& operator=(const Stack& other);

    // Добавление элемента в стек
    void push(const T& value);

    // Удаление элемента из стека
    void pop();

    // Получение верхнего элемента стека
    T& peek();

    // Проверка, пуст ли стек
    bool isEmpty() const;

    // Получение размера стека
    int size() const;
};

// Реализация методов шаблонного класса (всегда в заголовочном файле)
template <typename T>
Stack<T>::Stack(int capacity) : capacity(capacity), top(-1) {
    data = new T[capacity];
}

template <typename T>
Stack<T>::~Stack() {
    delete[] data;
}

template <typename T>
Stack<T>::Stack(const Stack& other) : capacity(other.capacity), top(other.top) {
    data = new T[capacity];
    for (int i = 0; i <= top; ++i) {
        data[i] = other.data[i];
    }
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
    if (this != &other) {
        delete[] data;
        capacity = other.capacity;
        top = other.top;
        data = new T[capacity];
        for (int i = 0; i <= top; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
void Stack<T>::push(const T& value) {
    if (top == capacity - 1) {
        throw std::overflow_error("Стек переполнен: не удается запушить в полный стек.");
    }
    data[++top] = value;
}

template <typename T>
void Stack<T>::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Опустошен стек: не удается извлечь файл из пустого стека.");
    }
    --top;
}

template <typename T>
T& Stack<T>::peek() {
    if (isEmpty()) {
        throw std::underflow_error("Стек пуст: не удается заглянуть в него.");
    }
    return data[top];
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return top == -1;
}

template <typename T>
int Stack<T>::size() const {
    return top + 1;
}

