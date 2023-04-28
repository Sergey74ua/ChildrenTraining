//Написать функцию, которая уменьшает введённое пользователем целое число (НЕ его копию!) в два раза.
//Перегрузить эту функцию, добавив возможность уменьшать число типа double.

#include <iostream>
using namespace std;

int div(int &n)
{
    return n /= 2;
}

double div(double &n)
{
    return n /= 2;
}

int main()
{
    int a;
    double b;

    cout << "Enter number (int):" << endl;
    cin >> a;
    cout << "Division (int): " << div(a) << endl << endl;

    cout << "Enter number (double):" << endl;
    cin >> b;
    cout << "Division (double): " << div(b) << endl;

    return 0;
}