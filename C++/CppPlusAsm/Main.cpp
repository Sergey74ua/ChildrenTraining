#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int num1;
	int num2;
	int result;

	cout << "¬ведите A и B :" << endl;
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
	cout << "сумма чисел : " << result << endl;
	system("pause>nul");

	//result = num1 * num2;
	__asm
	{
		mov eax, num1
		mov ebx, num2 //если закоментировать, ничего не изменитьс€.
		mul ebx
		mov result, eax
	}
	cout << "и их произведение : " << result << endl;
	system("pause>nul");

	cout << "¬ведите A и B :" << endl;
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
	cout << "разность : " << result << endl;
	system("pause>nul");

	cout << "¬ведите A и B :" << endl;
	cin >> num1;
	cin >> num2;
	//result = num1 / num2;
	__asm
	{
		mov eax, num1
		mov edx, 0	//необходимо указывать дл€ делени€
		mov ebx, num2
		div ebx
		mov result, eax
	}
	cout << "частное : " << result << endl;
	system("pause>nul");

	return 0;
}