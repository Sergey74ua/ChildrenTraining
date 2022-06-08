// Бинарные операции

#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int x = 0b0011; // 3
    int y = 0b0101; // 5
    int z;

    cout << "x = " << x << ", бинарный код: " << bitset<8>(x) << endl;
    cout << "y = " << y << ", бинарный код: " << bitset<8>(y) << endl << endl;

    cout << "Логическое И:" << endl;
    z = x & y;
    cout << "x = " << x << ", бинарный код: " << bitset<8>(x) << endl;
    cout << "y = " << y << ", бинарный код: " << bitset<8>(y) << endl;
    cout << "z = " << z << ", бинарный код: " << bitset<8>(z) << endl << endl;

    cout << "Логическое ИЛИ:" << endl;
    z = x | y;
    cout << "x = " << x << ", бинарный код: " << bitset<8>(x) << endl;
    cout << "y = " << y << ", бинарный код: " << bitset<8>(y) << endl;
    cout << "z = " << z << ", бинарный код: " << bitset<8>(z) << endl << endl;

    cout << "Логическое ЛИБО:" << endl;
    z = x ^ y;
    cout << "x = " << x << ", бинарный код: " << bitset<8>(x) << endl;
    cout << "y = " << y << ", бинарный код: " << bitset<8>(y) << endl;
    cout << "z = " << z << ", бинарный код: " << bitset<8>(z) << endl << endl;

    cout << "Логическое НЕ:" << endl;
    x = ~x;
    y = ~y;
    cout << "x = " << x << ", бинарный код: " << bitset<8>(x) << endl;
    cout << "y = " << y << ", бинарный код: " << bitset<8>(y) << endl << endl;

    cout << "Побитовый сдвиг влево:" << endl;
    x = 3;
    z = x << 1;
    cout << "x = " << x << ", сдвиг влево: " << bitset<8>(x) << endl;
    cout << "z = " << z << ", сдвиг влево: " << bitset<8>(z) << endl;
    cout << "Побитовый сдвиг вправо:" << endl;
    y = 5;
    z = y >> 1;
    cout << "y = " << y << ", сдвиг влево: " << bitset<8>(y) << endl;
    cout << "z = " << z << ", сдвиг влево: " << bitset<8>(z) << endl << endl;

    cout << "x &= 6 " << " - " << (x &= 6) << " - " << bitset<8>(x) << endl;
    cout << "x |= 7 " << " - " << (x |= 7) << " - " << bitset<8>(x) << endl;
    cout << "x ^= 8 " << " - " << (x ^= 8) << " - " << bitset<8>(x) << endl;
    cout << "x <<= 1 " << " - " << (x <<= 1) << " - " << bitset<8>(x) << endl;
    cout << "x >>= 1 " << " - " << (x >>= 1) << " - " << bitset<8>(x) << endl;

    system("pause>nul");
}
