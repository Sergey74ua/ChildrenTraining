#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int num1;
	int num2;
	int result;

	cin >> num1;
	cin >> num2;

	//result = num1 + num2;
	__asm
	{
		mov eax, num1 //5
		mov ebx, num2 //6
		//add eax, num2
		add eax, ebx
		mov result, eax
	}
	cout << "����� ����� : " << result << endl;
	system("pause");

	//result = num1 * num2;
	__asm
	{
		mov eax, num1
		mov ebx, num2 //���� ���������������, ������ �� ����������.

		mul ebx

		mov result, eax
	}
	cout << "������������ : " << result << endl;
	system("pause");

	//sub - �����, div - �������
	//

	return 0;
}