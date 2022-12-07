//Дополнить калькулятор, реализованный на вебинаре. Добавить возможность возведения в квадрат и вычисления остатка от деления.

#include <iostream>
using namespace std;

int main()
{
    double x = 0;
    double y = 0;
    char n = ' ';
    cin >> x;
    cin >> n;
    cin >> y;
    switch (n)
    {
        case '+': cout << "Result: " << x + y; break;
        case '-': cout << "Result: " << x - y; break;
        case '*': cout << "Result: " << x * y; break;
        case '/': cout << "Result: " << x / y; break;
        case '^': cout << "Result: " << pow(x, y); break;
        case '%': cout << "Result: " << fmod(x, y); break;
        default: cout << "Wrong operator";
    }
    return 0;
}