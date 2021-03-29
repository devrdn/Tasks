#include <iostream>
using namespace std;

struct STACK {
    char c;
    struct STACK* next;
};


using Node = STACK*;

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

int main()
{
    Node stack = nullptr;

    char br_open[3] = { '(', '[', '{' }; // Открывющиеся скобки.
    char br_close[3] = { ')', ']', '}' }; // Закрывающиеся скобки.
    int n_br1 = sizeof(br_open) / sizeof(decltype(br_open[0]));
    int n_br2 = sizeof(br_close) / sizeof(decltype(br_close[0]));

    char str[80]{ "{(1 + 2) + [(3-7) - x] + 4}" }; // Вводимая строка.
    int n = strlen(str); // Длина строки str.
    bool flag = true;
        
    for (int i = 0; i < n; i++) {

        flag = true;
        for (int k = 0; k < n_br1; k++) {
            // Проверка, есть ли открывающиеся скобка.
            if (str[i] == br_open[k]) {
                push(stack, str[i]);
                flag = false;
                break;
            }
        }

        if (flag == true) {
            for (int k = 0; k < n_br2; k++) {
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
    cout << boolalpha << "\nIs Stack Empty = " << isEmpty(stack) << endl;
    if (isEmpty(stack))
        cout << "\nExpression is correct!" << endl;
    else
        cout << "\nExpression is not correct!";

    system("pause > nul");
}
