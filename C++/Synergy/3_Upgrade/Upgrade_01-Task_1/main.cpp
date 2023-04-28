/*В заголовочном файле inout.h объявлены функции :
#include <vector>
void print(const std::vector<int>& vec);
void read(std::vector<int>& vec);

В файле main.cpp содержится следующий код :
#include <algorithm>

int main() {
    std::vector<int> vec;
    read(vec);
    std::sort(vec.begin(), vec.end());
    print(vec);
    return 0;
}

1.	Создайте файл print.cpp и реализуйте в ней функцию, объявленную в заголовочном файле.Она принимает ссылку на вектор и выводит все его значения на экран
2.	Создайте файл read.cpp и реализуйте в ней функцию, объявленную в заголовочном файле.Она принимает ссылку на вектор и заполняет его значениями, введенными
    пользователем с клавиатуры. Формат ввода - в первой строчке задается длина вектора, во второй - его элементы.
3.	В файле сценария сборки CMake пропишите создание библиотеки inoutlib из файлов read.cpp и print.cpp.Подключите ее к основной цели проекта
4.	В файле main.cpp подключите заголовочный файл  inout.h и протестируйте работу программы

Пример ввода :
5
6 3 2 1 4
Вывод :
1 2 3 4 6
*/

#include "inout.h"
#include <algorithm>

int main() {
    std::vector<int> vec;
    read(vec);
    std::sort(vec.begin(), vec.end());
    print(vec);
    return 0;
}