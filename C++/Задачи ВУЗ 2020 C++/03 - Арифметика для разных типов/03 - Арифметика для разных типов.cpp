#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    int A1, B1;
    double A2, B2;

    cout << "Введите первое число типа int (А): ";
    cin >> A1;
    cout << "Введите второе число типа int (B): ";
    cin >> B1;
    cout << "Результат выражения A+B :" << A1 + B1 << endl;
    cout << "Результат выражения A-B :" << A1 - B1 << endl;
    cout << "Результат выражения A*B :" << A1 * B1 << endl;
    if (B1 != 0)
        cout << "Результат выражения A/B :" << A1 / B1 << endl;
    else
        cout << "Ошибка: попытка деления на ноль" << endl;
    cout << endl;

    cout << "Введите первое число типа double (А): ";
    cin >> A2;
    cout << "Введите второе число типа double (B): ";
    cin >> B2;
    cout << "Результат выражения A+B :" << A2 + B2 << endl;
    cout << "Результат выражения A-B :" << A2 - B2 << endl;
    cout << "Результат выражения A*B :" << A2 * B2 << endl;
    if (B2 != 0)
        cout << "Результат выражения A/B :" << A2 / B2 << endl;
    else
        cout << "Ошибка: попытка деления на ноль" << endl;
    cout << endl;

    cout << "Введите первое число типа int (А): ";
    cin >> A1;
    cout << "Введите второе число типа double (B): ";
    cin >> B2;
    cout << "Результат выражения A+B :" << A1 + B2 << endl;
    cout << "Результат выражения A-B :" << A1 - B2 << endl;
    cout << "Результат выражения A*B :" << A1 * B2 << endl;
    if (B2 != 0)
        cout << "Результат выражения A/B :" << A1 / B2 << endl;
    else
        cout << "Ошибка: попытка деления на ноль" << endl;
    cout << endl;

    cout << "Введите первое число типа double (А): ";
    cin >> A2;
    cout << "Введите второе число типа int (B): ";
    cin >> B1;
    cout << "Результат выражения A+B :" << A2 + B1 << endl;
    cout << "Результат выражения A-B :" << A2 - B1 << endl;
    cout << "Результат выражения A*B :" << A2 * B1 << endl;
    if (B1 != 0)
        cout << "Результат выражения A/B :" << A2 / B1 << endl;
    else
        cout << "Ошибка: попытка деления на ноль" << endl;

    system("pause>nul");
    return 0;
}