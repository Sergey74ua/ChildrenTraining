#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int num1;
	int num2;
	int result;

	cout << "������� A � B :" << endl;
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
	system("pause>nul");

	//result = num1 * num2;
	__asm
	{
		mov eax, num1
		mov ebx, num2 //���� ���������������, ������ �� ����������.
		mul ebx
		mov result, eax
	}
	cout << "� �� ������������ : " << result << endl;
	system("pause>nul");

	cout << "������� A � B :" << endl;
	cin >> num1;
	cin >> num2;
	//result = num1 - num2;
	__asm
	{
		mov eax, num1
		mov ebx, num2
		sub eax, ebx
		mov result, eax
	}
	cout << "�������� : " << result << endl;
	system("pause>nul");

	cout << "������� A � B :" << endl;
	cin >> num1;
	cin >> num2;
	//result = num1 / num2;
	__asm
	{
		mov eax, num1
		mov edx, 0	//���������� ��������� ��� �������
		mov ebx, num2
		div ebx
		mov result, eax
	}
	cout << "������� : " << result << endl;
	system("pause>nul");

	return 0;
}