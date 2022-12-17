//Пользователь вводит 2 различных строки в консоль. 
//Считать эти строки и вывести их размер в консоль.

#include <iostream>
using namespace std;

int main()
{
    string s1;
    string s2;

    cout << "Enter two string:" << endl;

    cin >> s1;
    cin >> s2;

    cout << "First string size: " << s1.size() << endl;
    cout << "Second string size: " << s2.size() << endl;

    return 0;
}