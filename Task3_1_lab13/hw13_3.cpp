#include <stdio.h>
#include <ctype.h>
#include <color.h>
#include <string>
#include <iostream>
#define MAX_SIZE 40

using namespace std;

inline bool isLastSymbol(char * str, char);
inline bool isFirstSymbol(char * str, char);
inline bool isDivide(int, int);
void backWord(char *);
void printString(char *);


int main () {

    char * str;
    char * temp;
    int n;
    char sel;

    do {
        system("cls");
        str = new char[MAX_SIZE];
        printf(" MENU: \n"
               "1) First condition\n"
               "2) Second condition\n"
               "3) Third condition\n"
               "> ");
        sel = getche();
        printf("\n>> Enter String > ");
        gets(str);
        printString(str);



        switch(sel) {

            // Первое условие.
            case '1':
            {
                temp = strtok(str, " ,");
                short count = 0;
                while (temp != nullptr) {
                    if (isLastSymbol(temp, 'd')) {
                        printf("\nWord with last symbol %c: %s.\n", 'd', temp); count++;
                        break;
                    }

                    temp = strtok (nullptr, " ,");
                }
                if (count == 0) printf("\nNo some words.");
                break;
            }

            // Второе условие.
            case '2':
            {
                temp = strtok(str, " ,");
                short count = 0;
                while (temp != nullptr) {
                    if (isLastSymbol(temp, 'd') && isFirstSymbol(temp, 'a')) {
                        printf("\nWord with first symbol %c and last symbol %c is: %s.\n", 'a', 'd', temp); count++;
                        break;
                    }
                    temp = strtok (nullptr, " ,");
                }
                if (count == 0) printf("\nNo some words.");
                break;
            }

            // Третье условие.
            case '3':
            {
                printf("\n>> Result\n\n");
                short flag = 1;
                temp = strtok(str, " ,");
                while (temp != nullptr) {
                    if (isDivide(flag,2))
                        backWord(temp);
                    flag += 1;
                    temp = strtok (nullptr, " ,");
                }

                break;
            }

            // Выход из switch.
            default:
                break;
        }
        delete[] str;
        system("pause > nul");

    } while (sel != 'c');
    system("pause > nul");
}



void printString(char * _str) {
    // Output a string.
    // _str - string.
    printf("\n>> String: \n\n");
    for (int i = 0; _str[i]; i++) printf("%3i", i); printf("\n");
    for (int i = 0; _str[i]; i++) printf("%3c", _str[i]);
    printf("\n\n");
}

void backWord(char * _str) {
    // Написать строку _str наоборот.
    printf(" ");
    for(int i = strlen(_str); i >= 0; i--) {
        printf("%c", _str[i]);
    }

}

inline bool isDivide(int a, int b) {
    // Проверить если число a, делится на число b.
    return a % b == 0?true: false;
}


inline bool isFirstSymbol(char * str, char symbol) {
    // Проверка, если первый символ строки равен.
    // str - строка.
    // symbol - символ.
    if (strchr(str, symbol) - str == 0)
        return true;
    return false;
}


inline bool isLastSymbol(char *  str, char symbol) {
    // Проверка, если последний символ строки равен.
    // str - строка.
    // symbol - символ.
    if (strrchr(str, symbol) - str == strlen(str) - 1)
        return true;
    return false;
}

