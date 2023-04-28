//1. Отловить пять любых стандартных типов исключений (например: out_of_range или length_error) в одной программе с помощью try и нескольких блоков catch

#include <iostream>

int main()
{
    int x = -300;

    try
    {
        if (x >= 256)
            throw std::overflow_error("over 256");
        if (x < 0)
            throw std::underflow_error("less than 0");
        if (x < 0 || x >= 256)
            throw std::out_of_range("less than 0 or more than 256");
        if (x < INT_MIN || x > INT_MAX)
            throw std::length_error("int size exceeded");
        if (sizeof(x) != 4)
            throw std::runtime_error("error in process");
        std::cout << x << std::endl;
    }
    catch (std::overflow_error err)     //1. Результат превышает допустимый диапазон
    {
        std::cout << "Overflow error: " << err.what() << std::endl;
    }
    catch (std::underflow_error err)    //2. Результат меньше допустимого диапазона
    {
        std::cout << "Underflow error: " << err.what() << std::endl;
    }
    catch (std::out_of_range err)       //3. Выход за пределы диапазона
    {
        std::cout << "Out of range: " << err.what() << std::endl;
    }
    catch (std::length_error err)       //4. Превышем размер типа данных
    {
        std::cout << "Length error: " << err.what() << std::endl;
    }
    catch (std::runtime_error err)      //5. Ошибка во время выполнения
    {
        std::cout << "Runtime error: " << err.what() << std::endl;
    }

    return 0;
}