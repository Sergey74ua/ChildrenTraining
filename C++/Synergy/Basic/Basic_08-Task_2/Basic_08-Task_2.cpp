//2. Написать программу, которая пытается открыть для чтения несуществующий файл, обработать это с помощью try catch.

#include <iostream>
#include <fstream>

int main()
{
    std::string path = "test.txt";
    std::ifstream file;

    try
    {
        file.open(path);

        if (!file)
            throw "file no found";

        while (!file.eof())
            file.get();
        file.close();
    }
    catch (const char* err)
    {
        std::cout << "File opening error: " << err << std::endl;
    }

    return 0;
}