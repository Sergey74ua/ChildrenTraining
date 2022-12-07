//Создать массив из 10 чисел, найти и вывести наибольший элемент.

#include <iostream>
using namespace std;

int main()
{
	int arr[10] = {};
	int m = 0;

	//Заполняем массив случайными числами
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand();
		cout << arr[i] << " ";
		if (arr[i] > m)
			m = arr[i];
	}

	//Наибольший элемент
	cout << endl << m << endl;

	cin.get();
	return 0;
}