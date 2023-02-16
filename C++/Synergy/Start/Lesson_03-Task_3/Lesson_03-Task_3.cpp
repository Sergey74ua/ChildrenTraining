//Найти все делители данного натурального числа.

#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		if (n % i == 0)
			cout << " " << i;
	}
	cin.get();
	return 0;
}