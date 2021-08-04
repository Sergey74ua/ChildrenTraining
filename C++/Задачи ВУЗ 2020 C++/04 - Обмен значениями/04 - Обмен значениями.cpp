#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    int A, B, temp;
    cout << "Введите первое число (А): ";
    cin >> A;
    cout << "Введите второе число (B): ";
    cin >> B;

    temp = A;
    A = B;
    B = temp;
    cout << "Меняем числа с дополнительной переменной (A, B): " << A << " " << B << endl;

    A ^= B ^= A ^= B;
    cout << "Меняем числа без дополнительной переменной (A, B): " << A << " " << B << endl;

    system("pause>nul");
    return 0;
}