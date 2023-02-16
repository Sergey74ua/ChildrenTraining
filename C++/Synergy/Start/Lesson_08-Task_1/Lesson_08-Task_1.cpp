//Написать программу, в которой объявлены функции sum() и mult(), первая функция возвращает сумму двух чисел,
//а вторая возвращает произведение двух чисел. В функции main() попросить пользователя ввести два числа,
//после чего вывести результаты выполнения функций sum() и mult() для введённых чисел.

#include <iostream>
using namespace std;

int sum(int a, int b)
{
    return a + b;
}

int mult(int a, int b)
{
    return a * b;
}

int main()
{
    int a, b;
    cout << "Enter two numbers:" << endl;
    cin >> a >> b;
    cout << "Sum of numbers: " << sum(a, b) << endl;
    cout << "Multiplication: " << mult(a, b) << endl;

    return 0;
}