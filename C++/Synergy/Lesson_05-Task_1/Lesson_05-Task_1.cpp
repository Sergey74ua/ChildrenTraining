//Создать 4 указателя на различные типы данных. Вывести адреса этих указателей. Попросить пользователя ввести значения для данных указателей.
//Вывести введённые значения с помощью операции разыменования.

#include <iostream> 
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    int x1;
    short x2;
    double x3;
    bool x4;

    int *p1 = &x1;
    short *p2 = &x2;
    double *p3 = &x3;
    bool *p4 = &x4;

    cout << "Вывод адресов указателей:" << endl;
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    cout << p4 << endl;
    
    cout << "Введите число (int): ";
    cin >> x1;
    cout << "Введите число (short): ";
    cin >> x2;
    cout << "Введите число (double): ";
    cin >> x3;
    cout << "Введите 0 или 1 (bool): ";
    cin >> x4;

    cout << "Вывод операцией разименованием:" << endl;
    cout << *p1 << endl;
    cout << *p2 << endl;
    cout << *p3 << endl;
    cout << *p4 << endl;

    return 0;
}