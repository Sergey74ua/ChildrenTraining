#include <iostream>
#include <ctime>
	using namespace std;
void main()
{
	setlocale(LC_ALL, "RUS");
	system("title Больше - меньше!");
	system("color 0a");
	srand(time(NULL));
	cout << endl;
L1:
	int S, N = 0, R = rand() % 1000 + 1;
	cout << " Удачи в новой игре!" << endl << endl;
L2:
	cout << " Всего попыток: " << N << endl << endl;
	cout << " Угадай число (1-1000): ";
	cin >> S;
	N++;
	system("cls");
	if (S == R)
	{
		cout << endl << " УГАДАЛ" << " c " << N << " попыток ... ";
		goto L1;
	}
	else if (S > R)
	{
		cout << endl << " МЕНЬШЕ" << endl << endl;
		goto L2;
	}
	else if (S < R)
	{
		cout << endl << " БОЛЬШЕ" << endl << endl;
		goto L2;
	}
}