//Написать программу, в которой будет рекурсивная функция подсчёта степени числа.

#include <iostream>
using namespace std;

int power(int a, int n)
{
	if (n <= 1)
		return a;
	return a *power(a, --n);
}

int main()
{
	int a, n;
	cout << "Enter number and power:" << endl;
	cin >> a >> n;
	cout << "Number " << a << " to the power of " << n << " = " << power(a, n) << endl;
    return 0;
}