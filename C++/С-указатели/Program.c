#include <stdio.h>

int main(void)
{
	int x=1;

	printf("%d\n", x); //�������� ����������
	printf("%p\n", &x); //����� ������ ������ ����������

	int* p = &x;
	printf("%p\n", p); //����� ���������� ������ ������
	printf("%d\n", *p); //����� ���������� �� ������ ������

	p++;
	printf("%p\n", p); //������� �� ������� ������
	printf("%d\n", *p); //����� ���������� �� ������ ������

	system("pause>nul");
	return 0;
}