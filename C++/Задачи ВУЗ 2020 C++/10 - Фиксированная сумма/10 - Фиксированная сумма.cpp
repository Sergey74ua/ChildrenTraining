#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    int s, l1, r1, l2, r2;

    cout << "Введите через пробел число и два диапазона чисел (s l1 r1 l2 r2): ";
    cin >> s >> l1 >> r1 >> l2 >> r2;

    if (abs(s) > 1e15 || abs(l1) > 1e15 || abs(r1) > 1e15 || abs(l2) > 1e15 || abs(r2) > 1e15) {
        cout << "Некорректный ввод" << endl;
        system("pause>nul");
        return 0;
    }

    if (s < l1 + l2 || s > r1 + r2)
        cout << -1;
    else if (s - l1 <= r2)
        cout << l1 << " " << s - l1;
    else
        cout << s - r2 << " " << r2;

    system("pause>nul");
    return 0;
}