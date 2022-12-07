//Создать массив из первых 10 нечётных чисел.

#include <iostream>
using namespace std;

int main()
{
	int arr[10] = {};

	//Заполняем массив
	for (int i = 0; i < 10; i++)
		arr[i] = i * 2 + 1;

	//Выводим массив
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";

	cin.get();
	return 0;
}