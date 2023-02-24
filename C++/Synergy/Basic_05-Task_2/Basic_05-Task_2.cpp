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
    T n;

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
    string t = typeid(n).name();
    int s = sizeof(n);
};

int main()
{
    Info<bool> x_bool(true);
    x_bool.getInfo();

    Info<char> x_char(62);
    x_char.getInfo();

    Info<short> x(123);
    x.getInfo();

    Info<float> y(123.456);
    y.getInfo();

    return 0;
}