//Создать и отсортировать по невозрастанию массив из 10 чисел, вывести среднее арифметическое его элементов.

#include <iostream>
using namespace std;

int main()
{
	int arr[10] = {};
	int s = 0;

	//Заполняем массив случайными числами
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand();
		s += arr[i];
	}

	//Выводим несортированный массив
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << endl;

	//Сортируем массив (пузырьком)
	int temp;
	for (int i = 0; i < 10; i++)
		for (int j = i+1; j < 10; j++)
			if (arr[i]<arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}

	//Выводим сортированный массив
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";

	//Среднее арифметическое
	cout << endl << s / 10 << endl;

	cin.get();
	return 0;
}