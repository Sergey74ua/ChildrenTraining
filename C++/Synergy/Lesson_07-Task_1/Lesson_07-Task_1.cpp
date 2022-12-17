//Объявить произвольную строку четырьмя различными способами, вывести эти строки в консоль

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1;
	string s2 = "  Hello";
	string s3("  world");
	string s4(9, '|');
	s1 = s4;

	cout << s1 << endl << s2 << endl << s3 << endl << s4 << endl;

	return 0;
}