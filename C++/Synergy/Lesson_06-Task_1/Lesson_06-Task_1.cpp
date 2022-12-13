//Создать свой вариант простейшего ГПСЧ, вывести 100 полученных чисел.

#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
            cout << (time(0) * j + clock() * i) % 100 << " ";
        cout << endl;
    }
    return 0;
}