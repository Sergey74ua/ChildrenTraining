#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    double A, B;
    char act;

    cout << "Введите арифметическое действие через пробел : ";
    cin >> A >> act >> B;

    if (act == '+')
        cout << A + B;
    else if (act == '-')
        cout << A - B;
    else if (act == '*')
        cout << A * B;
    else if (act == '/')
        cout << A / B;
    else
        cout << "неопределенное действие" << endl;

    system("pause>nul");
    return 0;
}