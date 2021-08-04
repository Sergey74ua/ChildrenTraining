#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    int h1, m1, h2, m2, period;
    char c;

    cout << "Введите первое время (чч:мм): ";
    cin >> h1 >> c >> m1;
    cout << "Введите второе время (чч:мм): ";
    cin >> h2 >> c >> m2;

    if (h1 < 0 or h1 > 23 or h2 < 0 or h2 > 23 or m1 < 0 or m1 > 59 or m2 < 0 or m2 > 59) {
        cout << "Некорректный ввод" << endl;
        system("pause>nul");
        return 0;
    }

    if (h1 == 23 && h2 == 0)
        h2 += 24;

    period = abs((h2 * 60 + m2) - (h1 * 60 + m1));
    
    if (period <= 15)
        cout << "Встреча состоится" << endl;
    else
        cout << "Встреча не состоится" << endl;

    system("pause>nul");
    return 0;
}