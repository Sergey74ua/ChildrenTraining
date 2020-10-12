#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    int n, s;
    cout << "Введите число: ";
    cin >> n;

    if (n < 2 || n > 1e9) {
        cout << "Некорректный ввод";
        system("pause>nul");
        return 0;
    }

    s = 0;
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            s += 1;

    if (s == 2)
        cout << "Простое число" << endl;
    else
        cout << "Составное число" << endl;

    system("pause>nul");
    return 0;
}