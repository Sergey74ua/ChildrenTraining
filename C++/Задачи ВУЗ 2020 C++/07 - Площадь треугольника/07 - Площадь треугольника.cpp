#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    double a, b, c, xA, yA, xB, yB, xC, yC, P, S;
    int form;

    cout << "Выберите способ ввода параметров треугольника:" << endl;
    cout << "1. Длины сторон" << endl;
    cout << "2. Координаты вершин" << endl;

    while (true) {
        cin >> form;
        if (abs(form) > 1000) {
            cout << "Некорректные данные" << endl;
            system("pause>nul");
            return 0;
        }

        if (form == 1) {
            cout << "Введите сторону a: ";
            cin >> a;
            cout << "Введите сторону b: ";
            cin >> b;
            cout << "Введите сторону c: ";
            cin >> c;
            break;
        }

        else if (form == 2) {
            cout << "Введите вершины A через пробел: ";
            cin >> xA >> yA;
            cout << "Введите вершины B через пробел: ";
            cin >> xB >> yB;
            cout << "Введите вершины C через пробел: ";
            cin >> xC >> yC;
            a = sqrt(pow((xB - xA), 2) + pow((yB - yA), 2));
            b = sqrt(pow((xC - xA), 2) + pow((yC - yA), 2));
            c = sqrt(pow((xB - xC), 2) + pow((yB - yC), 2));
            break;
        }

        else {
            cout << "ошибочный ввод" << endl;
            continue;
        }
    }

    if (a > b + c || b > a + c || c > a + b)
        cout << "Некорректные данные" << endl;
    else {
        P = (a + b + c) / 2;
        S = sqrt(P * (P - a) * (P - b) * (P - c));
        cout << "S = " << S;
    }

    system("pause>nul");
    return 0;
}