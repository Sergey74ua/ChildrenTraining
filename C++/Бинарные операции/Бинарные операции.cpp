// Бинарные операции

#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int x = 0b0011; // 3
    int y = 0b0101; // 5

    cout << "x =" << x << ", бинарный код: " << bitset<8>(x) << endl;
    cout << "y =" << y << ", бинарный код: " << bitset<8>(y) << endl << endl;

    cout << "Логическое НЕ:" << endl;
    x = ~x;
    y = ~y;
    cout << "x =" << x << ", бинарный код: " << bitset<8>(x) << endl;
    cout << "y =" << y << ", бинарный код: " << bitset<8>(y) << endl << endl;

    cout << "Логическое И:" << endl;
    x = ~x;
    y = ~y;
    cout << "x =" << x << ", бинарный код: " << bitset<8>(x) << endl;
    cout << "y =" << y << ", бинарный код: " << bitset<8>(y) << endl << endl;

    system("pause>nul");
}

