#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    int n, f;
    cout << "Введите число: ";
    cin >> n;
    f = 1;

    for (int i = 2; i <= n; i++)
        f *= i;

    if (f > 1e9)
        cout << "Некорректный вывод" << endl;
    else
        cout << "Факториал: " << f << endl;

    system("pause>nul");
    return 0;
}