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

		label:					;метка для цикла
			mul esi
			inc esi
		cmp esi, count
		jng label				;переход на метку

		mov factorial, eax
	}

	cout << "факториал: " << factorial << endl;
	system("pause");

	return 0;
}
