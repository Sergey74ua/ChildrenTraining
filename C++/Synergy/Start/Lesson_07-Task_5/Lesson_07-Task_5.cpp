//Пользователь вводит в консоль своё имя. Записать в файл строку, приветствующую
//пользователя по имени, затем считать эту строку из файла и вывести её в консоль.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string text;
    cout << "Your name: ";
    cin >> text;

    ofstream newFile;
    newFile.open("Hello.txt");
    if (newFile.is_open())
    {
        text = "Hello, " + text;
        newFile << text << endl;
    }
    else
        cout << "Error";
    newFile.close();

    ifstream file("Hello.txt");
    if (file.is_open())
    {
        while (getline(file, text))
        {
            cout << "from file: " << text << endl;
        }
    }
    else
        cout << "Error";
    cout << text << endl;
    file.close();
}