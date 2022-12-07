//Составить 10 выражений с различными переменными и операциями. Вывести результат в поток ввода-вывода.

#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int b = 8;
    int c = 4;

    int x1 = a + b;
    int x2 = b - a;
    int x3 = b * a;
    int x4 = a / c;
    int x5 = pow(a, b);
    int x6 = sqrt(b);
    int x7 = c % a;
    int x8 = (a + b + c) / 2;
    int x9 = pow(sqrt(a + b), c);

    string q = "Hello";
    string w = "World";
    string x10 = q + w;

    cout << x1 << endl;
    cout << x2 << endl;
    cout << x3 << endl;
    cout << x4 << endl;
    cout << x5 << endl;
    cout << x6 << endl;
    cout << x7 << endl;
    cout << x8 << endl;
    cout << x9 << endl;
    cout << x10 << endl;

    cin.get();
}