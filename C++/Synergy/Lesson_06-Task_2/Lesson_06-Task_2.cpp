//С помощью функций rand() и srand() создайте ГПСЧ, который выводит количество очков, полученных при бросании двух игральных кубиков.
//Не забудьте учесть теорию вероятностей. Выведите не менее 100 исходов.

#include <iostream>
using namespace std;

int main()
{
    srand(time(NULL));

    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
            cout << (rand() % 6 + 1) + (rand() % 6 + 1) << " ";
        cout << endl;
    }

    return 0;
}