#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    int x, n, s;

    cout << "Введите число: ";
    cin >> x;
    cout << "Введите степень: ";
    cin >> n;

    s = 0;
    if (n != 0) {
        s = x;
        for (int i = 1; i < n; i++)
            s *= x;
    }
    cout << "Результат: " << s;

    system("pause>nul");
    return 0;
}