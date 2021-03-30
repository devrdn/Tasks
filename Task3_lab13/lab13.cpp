#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define EXIT_ERROR -1

void printString(char *);
inline void deleteSymbols(char *, int, int);
inline int pos(char, char *, char = 'L');

int main () {

    char * str;
    int pos1, pos2;
    str = new char[20];
    printf(">> Enter new String: ");
    gets(str); // Enter the string.
    printString(str); // Output string str.
    if ((pos1 = pos('<', str)) == -1  || (pos2 = pos('>', str)) == -1)
        printf("\nString doesn't contains both symbols: '<' and '>'.");
    else {
        if (pos1 == 0 && pos2 == strlen(str) - 1)
            printf("\nAll word is Between <>.");
        else if (pos1 > pos2)
            printf("\nThe position of the element '>' is earlier than the position of the element '<'.");
        else {
            do {
                deleteSymbols(str, pos1, pos2); // Delete symbols from pos1 to pos2.
                pos1 = pos('<', str, 'F');
                pos2 = pos('>', str);
            } while (pos1 != -1 && pos2 != -1);
            printString(str);
        }
    }
    delete[] str;
    system("pause > nul");
}

inline void deleteSymbols(char * _str, int _pos1, int _pos2) {
    // Removing a character from a string from the pos1 to pos2 positions.
    // _str - string.
    // _pos1 - from position.
    // _pos2 - to position.
    strcpy(_str + _pos1, _str + _pos2 + 1);
}

inline int pos(char _element, char * _str, char _option) {
    // Find position of the character in the string.
    // _element - necessary element.
    // _str - string.
    // _option (F - first occurrence of character,
    //          L - last occurrence of character).
    if (!strchr(_str, _element)) return EXIT_ERROR;
    else if(_option == 'F') return strchr(_str, _element)- (_str);
    return strrchr(_str, _element)- (_str);
}

void printString(char * _str) {
    // Output a string.
    // _str - string.
    printf("\n>> String: \n\n");
    for (int i = 0; _str[i] != '\0'; i++) printf("%3i", i); printf("\n");
    for (int i = 0; _str[i] != '\0'; i++) printf("%3c", _str[i]);
    printf("\n\n");
}
