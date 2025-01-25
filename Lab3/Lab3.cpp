// main.cpp
#include "Stack.h"
#include <iostream>
#include <clocale>

int main() {
    try {
        setlocale(LC_CTYPE, "rus");
        // Инстанцирование шаблона для типа int
        Stack<int> intStack;
        intStack.push(11);
        intStack.push(20);
        intStack.push(33);

        std::cout << "Top element of intStack: " << intStack.peek() << std::endl;
        intStack.pop();
        std::cout << "Top element after pop: " << intStack.peek() << std::endl;

        // Инстанцирование шаблона для типа double
        Stack<double> doubleStack;
        doubleStack.push(3.14);
        doubleStack.push(2.71);

        std::cout << "Top element of doubleStack: " << doubleStack.peek() << std::endl;

        // Инстанцирование шаблона для типа std::string
        Stack<std::string> stringStack;
        stringStack.push("Как дела");
        stringStack.push("Что делаешь");

        std::cout << "Top element of stringStack: " << stringStack.peek() << std::endl;

        // Попытка извлечения из пустого стека
        Stack<int> emptyStack;
        emptyStack.pop();  // Это вызовет исключение

    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}