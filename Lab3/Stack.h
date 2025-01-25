#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

template <typename T>
class Stack {
private:
    T* data;        // ��������� �� ������������ ������
    int capacity;   // ����������� �����
    int top;        // ������ �������� �������� �����

public:
    // �����������
    Stack(int capacity = 10);

    // ����������
    ~Stack();

    // ���������� �����������
    Stack(const Stack& other);

    // �������� ������������
    Stack& operator=(const Stack& other);

    // ���������� �������� � ����
    void push(const T& value);

    // �������� �������� �� �����
    void pop();

    // ��������� �������� �������� �����
    T& peek();

    // ��������, ���� �� ����
    bool isEmpty() const;

    // ��������� ������� �����
    int size() const;
};

// ���������� ������� ���������� ������ (������ � ������������ �����)
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
        throw std::overflow_error("���� ����������: �� ������� �������� � ������ ����.");
    }
    data[++top] = value;
}

template <typename T>
void Stack<T>::pop() {
    if (isEmpty()) {
        throw std::underflow_error("��������� ����: �� ������� ������� ���� �� ������� �����.");
    }
    --top;
}

template <typename T>
T& Stack<T>::peek() {
    if (isEmpty()) {
        throw std::underflow_error("���� ����: �� ������� ��������� � ����.");
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

