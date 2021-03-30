#include <iostream>
unsigned long long factorial(int k);

int main()
{
    std::cout << "Factorial (5) = " << factorial(5);
    system("pause > nul");
}

// Факторил числа.
// k - число.
unsigned long long factorial(int k) {
    if (k < 0)
        throw 777;
    if (k == 0)
        return 1;
    return k * factorial(k - 1);
}