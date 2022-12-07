//Пользователь вводит 3 целых числа. Написать программу, выводящую меньшее из них.

#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int minimum;
    if (a <= b && a <= c)
        minimum = a;
    else if (b <= a && b <= c)
        minimum = b;
    else
        minimum = c;
    cout << minimum << endl;
    cin.get();
    return 0;
}