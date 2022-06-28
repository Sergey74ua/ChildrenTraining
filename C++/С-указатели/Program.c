#include <stdio.h>

int main(void)
{
	int x=1;

	printf("%d\n", x); //Значение переменной
	printf("%p\n", &x); //Вывод адреса памяти переменной

	int* p = &x;
	printf("%p\n", p); //Вывод переменной адреса памяти
	printf("%d\n", *p); //Вывод переменной по адресу памяти

	p++;
	printf("%p\n", p); //Переход по адресам памяти
	printf("%d\n", *p); //Вывод переменной по адресу памяти

	system("pause>nul");
	return 0;
}