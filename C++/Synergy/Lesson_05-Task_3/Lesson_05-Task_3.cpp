//Создать и заполнить вручную динамический массив вещественных чисел двойной точности. Размер массива и его значения вводит пользователь.

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    int s;
    cout << "Введите размер массива и его значения: " << endl;
    cin >> s;
    double *arr = new double[s];
    for (int i = 0; i < s; i++)
        cin >> arr[i];

    //Вывод массива
    for (int i = 0; i < s; i++)
        cout << arr[i] << " ";

    return 0;
}