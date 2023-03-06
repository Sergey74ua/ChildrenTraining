//3. Создать свой тип исключений, который не позволяет ввести пользователю цифру в символьный тип данных

#include <iostream>
#include <exception>
 
class CharException : public std::exception
{
public:
    CharException(const std::string msg = "error") : exception()
    {
        err = msg;
    }
    const char* what() const noexcept override
    {
        return err.c_str();
    }

private:
    std::string err;
};
 
int main()
{
    char x;

    try 
    {
        std::cout << "Enter a letter: ";
        std::cin >> x;
        if (isdigit(x))
            throw CharException("number entered");
        std::cout << x << std::endl;
    }
    catch (const std::exception& err)
    {
        std::cout << "Input error: " << err.what() << std::endl;
    }

    return 0;  
}