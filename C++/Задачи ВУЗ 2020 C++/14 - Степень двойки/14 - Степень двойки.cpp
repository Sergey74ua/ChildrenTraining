#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    long x, s, n;
    cout << "Введите число: ";
    cin >> x;

    if (x < 0 || x > 1e15) {
        cout << "Некорректный ввод" << endl;
        system("pause>nul");
        return 0;
    }
        
    s = 0;
    if (x != 0) {
        n = 1;
        while (n <= x) {
            n *= 2;
            s += 1;
        }
    }

    cout << "Количество степеней двойки: " << s << endl;

    system("pause>nul");
    return 0;
}