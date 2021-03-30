#include <iostream>
unsigned long long factorial(int);
int fact(int, int = 1);

int main()
{
    int n;
    std::cout << "Enter n = ";
    std::cin >> n;
    std::cout << "Factorial (" << n << ") = " << factorial(n) << std::endl;
    system("pause > nul");
}

// Factorial of a number.
// k - number.
unsigned long long factorial(int n) {
    if (n < 0)
        throw -1; // Error number.
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

// Factorial of a number.
// k - number.
int fact(int n, int result) {
    // Tail recursion.
    if (n < 0)
        throw - 1; // Error number.
    if (n == 0 || n == 1) 
        return result;
    else
        return fact(n - 1, n * result);
}