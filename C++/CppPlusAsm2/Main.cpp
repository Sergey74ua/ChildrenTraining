#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int count;
	int factorial = 1;

	cin >> count;

	__asm
	{
		mov esi, 1
		mov eax, factorial

		label:					;����� ��� �����
			mul esi
			inc esi
		cmp esi, count
		jng label				;������� �� �����

		mov factorial, eax
	}

	cout << "���������: " << factorial << endl;
	system("pause");

	return 0;
}
