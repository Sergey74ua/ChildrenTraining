#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    double x0, v0, t;
    cout << "Введите через пробел значения для x0, v0, t: ";
    cin >> x0 >> v0 >> t;
    cout << x0 + v0 * t - (9.8 * t * t) / 2;

    //Объяснение: Для С++ надо брать тип данных с плавающей точкой, для более точных расчетов.
    system("pause>nul");
    return 0;
}