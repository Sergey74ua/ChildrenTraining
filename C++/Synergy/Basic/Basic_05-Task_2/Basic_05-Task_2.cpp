//2. Реализовать шаблонный класс Info, хранящий информацию о некой переменной. Соответственно должны быть поля,
//хранящие информацию о типе данных переменной и о размере этой переменной в памяти. Должен быть реализован метод,
//выводящий значений этих полей, а также диапазон возможных значений соответствующего типа данных.

#include <iostream>
#include <limits>

using namespace std;

template <class T>

class Info
{
public:
    Info(T n)
    {
        this->n = n;
    }

    void getInfo()
    {
        cout << "value: " << n << endl;
        cout << "type: " << t << endl;
        cout << "size: " << s << " byte, " << s*8 << " bit." <<  endl;
        cout << "range: " << numeric_limits<T>::min() << " - " << numeric_limits<T>::max() << endl << endl;
    }

private:
    T n;
    string t = typeid(n).name();
    int s = sizeof(n);
};

int main()
{
    Info<bool> x_bool(true);
    x_bool.getInfo();

    Info<char> x_char(62);
    x_char.getInfo();

    Info<short> x_short(123);
    x_short.getInfo();

    Info<int> x_int(123456789);
    x_int.getInfo();

    Info<float> x_float(123.456);
    x_float.getInfo();

    Info<long long> x_long(123456789);
    x_long.getInfo();

    Info<double> x_double(1.23456789);
    x_double.getInfo();

    Info<string> x_string("Hello");
    x_string.getInfo();

    return 0;
}