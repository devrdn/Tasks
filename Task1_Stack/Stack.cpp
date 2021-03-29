#include <iostream>

struct STACK {
    char c;
    struct STACK* next;
};


using Node = STACK*;

void push(Node& Top, char c);
char pop(Node& Top);
char peek(Node& Top);
inline bool isEmpty(Node& Top);


int main()
{
    Node stack = nullptr;

    char br_open[4] = { "({[" }; // Открывющиеся скобки.
    char br_close[4] = { ")}]" }; // Закрывающиеся скобки.

    char* str; // Вводимая строка.
    str = new char[20];
    std::cin >> str; // Пользователь вводит выражение.
    bool flag = true;

    for (int i = 0; str[i]; i++) {

        flag = true;
        for (int k = 0; br_open[k]; k++) {
            // Проверка, есть ли открывающиеся скобка.
            if (str[i] == br_open[k]) {
                push(stack, str[i]);
                flag = false;
                break;
            }
        }

        if (flag == true) {
            for (int k = 0;  br_close[k]; k++) {
                // Проверка, есть ли закрывающиеся скобка.
                if (str[i] == br_close[k]) {
                    if (peek(stack) == br_open[k]) {
                        pop(stack);
                        break;
                    }
                    else {
                        push(stack, str[i]);
                    }
                }

            }
        }

    }
    std::cout << std::boolalpha << "\nIs Stack Empty = " << isEmpty(stack) << std::endl; // Проверка, если стэк пуст.
    if (isEmpty(stack))
        std::cout << "\nExpression is correct!" << std::endl; // Вывод сообщения, если выражение верное.
    else
        std::cout << "\nExpression is not correct!"; // Вывод сообщения, если выражение неверное..

    delete[] str;
    system("pause > nul");
}

// Добавление узла (в вершину стэка).
void push(Node& Top, char c) {
    Node newNode = new STACK;
    newNode->c = c;
    newNode->next = Top;
    Top = newNode;
}

// Возвращение узла из стэка.
char pop(Node& Top) {
    char c;
    Node tp = Top;
    if (Top == nullptr)
        return EXIT_FAILURE;
    c = Top->c;
    Top = Top->next;
    delete tp; // Освободить память.
    return c;
}

// Посмотреть элемент стэка.
char peek(Node& Top) {
    if (Top == nullptr)
        return EXIT_FAILURE;
    return Top->c;
}

// Проверка если узел пуст.
inline bool isEmpty(Node& Top) {
    return Top == nullptr;
}