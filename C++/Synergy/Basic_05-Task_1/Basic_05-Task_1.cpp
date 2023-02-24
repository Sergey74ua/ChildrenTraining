//1. Реализовать шаблонную функцию swap, которая меняет местами значения двух переменных любого типа.

#include <iostream>

using namespace std;

template <typename T>

void swap(T a, T b)
{
    T c = a;
    a = b;
    b = c;
    return a, b;
}

int main()
{
    string a, b;
    cout << "A = ";
    cin >> a;
    cout << "B = ";
    cin >> b;

    swap(a, b);

    cout << endl << "swap:" << endl;
    cout << "A = " << a << endl;
    cout << "B = " << b << endl;

    return 0;
}