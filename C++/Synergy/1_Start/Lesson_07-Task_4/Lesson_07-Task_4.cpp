//Пользователь вводит через пробел в консоль свои имя и фамилию. Получить 2 отдельные строки,
//где одна строка хранит имя, а другая фамилию. Использовать методы find() и erase().

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1, s2;
    int i;

    cout << "Enter first and last name:" << endl;
    getline(cin, s1);
    s2 = s1;
    i = s1.find(" ");

    s1 = s1.erase(i, size(s1)-i);
    s2 = s2.erase(0, i+1);

    cout << "First name: " << s1 << endl;
    cout << "Last name: " << s2 << endl;
    
    return 0;
}