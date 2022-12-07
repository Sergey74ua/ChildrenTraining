//Найти сумму числе от 1 до n (n вводит пользователь).

#include <iostream>
using namespace std;

int main()
{
	int s = 0;
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		s += i;
	}
	cout << s << endl;
	cin.get();
	return 0;
}