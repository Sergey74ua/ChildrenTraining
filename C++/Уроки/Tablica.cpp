#include <iostream>

using namespace std;

//������� ������ �������� �����
void line1(char S)
{
	cout << "  ";
	int i = 1;
	while (i <= 71)
	{
		i++;
		cout << S;
	}
	cout << endl;
}

//������� ������ ������ �����
void line2(char S)
{
	cout << "  " << S;
	int i = 1;
	do
	{
		i++;
		cout << "      " << S;
	}
	while (i <= 10);
	cout << endl;
}

//������� ������ ����� � �������
int line3(char S, int k)
{
	cout << "  " << S;
	for (int i = 1; i <= 10; i++)
	{
		int R = k * i;
		R < 10 ? (cout << "   ") : R < 100 ? (cout << "  ") : (cout << " ");
		cout << R << "  " << S;
	}
	cout << endl;
	return 0;
}

//�������� ���������
void main()
{
	setlocale(LC_ALL, "RUS");
	system("title ������� ���������.");
	system("mode con cols=76 lines=45");

	char S = '#';
	cout << endl << "             �  �  �  �  �  �  �     �  �  �  �  �  �  �  �  �" << endl << endl;
	line1(S);
	for (int k = 1; k <= 10; k++)
	{
		line2(S);
		line3(S, k);
		line2(S);
		line1(S);
	}
	system("pause>nul");
}