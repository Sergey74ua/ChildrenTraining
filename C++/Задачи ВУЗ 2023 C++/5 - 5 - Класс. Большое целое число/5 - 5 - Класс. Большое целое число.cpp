/* Напишите реализацию класса BigInt, который предназначен для работы с целыми числами неограниченной длины. Класс должен поддерживать:
основные математические операции: сложение, вычитание, умножение, деление. Гарантируется, что деления на 0 в тестах не будет;
операции сравнения чисел: равенство, больше, меньше;
создание объекта из строки и из обычного целого числа. Конструктор по умолчанию должен создавать число равное нулю;
вывод в стандартный поток.
Класс будет проверяться при помощи кода:

#include <iostream>
#include <string>

// Ваш код здесь

int main() {
    std::string a, b;
    std::cin >> a >> b;

    Bigint first(a);
    Bigint second(b);

    std::cout << "a + b = " << (first + second) << std::endl;
    std::cout << "a - b = " << (first - second) << std::endl;
    std::cout << "a * b = " << (first * second) << std::endl;
    std::cout << "a / b = " << (first / second) << std::endl;

    int c;
    std::cin >> c;
    Bigint third(c);
    Bigint zero;

    std::cout << "с > 0 = " << (third > zero) << std::endl;
    std::cout << "с < 0 = " << (third < zero) << std::endl;
    std::cout << "с == 0 = " << (third == zero) << std::endl;
}

Формат ввода
Два больших целых числа и одно число не превышающее по модулю 2⋅10^9
Формат вывода
Вывод согласно примерам

Пример 1
Ввод	Вывод
1234567891011121314 1234567891011121314 12345
a + b = 2469135782022242628
a - b = 0
a * b = 1524157877515647915340381231625086596
a / b = 1
с > 0 = 1
с < 0 = 0
с == 0 = 0
Пример 2
Ввод	Вывод
96730600406611605052 -3335537945055572588 256118
a + b = 93395062461556032464
a - b = 100066138351667177640
a * b = -322648588104261007331688957343573514576
a / b = -29
с > 0 = 1
с < 0 = 0
с == 0 = 0
*/

#include <iostream>
#include <string>
#include <algorithm>

class Bigint {
public:
    std::string number;
    bool isNegative;

    //Конструктор по умолчанию
    Bigint() {
        number = "0";
        isNegative = false;
    }

    //Конструктор из строки
    Bigint(const std::string& str) {
        if (str[0] == '-') {
            number = str.substr(1);
            isNegative = true;
        } else {
            number = str;
            isNegative = false;
        }
        removeLeadingZeros();
    }

    //Конструктор из числа
    Bigint(int n) {
        if (n < 0) {
            number = std::to_string(-n);
            isNegative = true;
        } else {
            number = std::to_string(n);
            isNegative = false;
        }
    }

    //Сложение больших чисел
    Bigint operator+(const Bigint& other) const {
        if (isNegative != other.isNegative) {
            if (isNegative)
                return other - (*this*-1);
            else
                return *this - (other*-1);
        }

        std::string result;
        int carry = 0;
        int maxLength = std::max(number.size(), other.number.size());

        for (int i = 0; i < maxLength || carry; i++) {
            int sum = carry;
            if (i < number.size())
                sum += number[number.size() - 1 - i] - '0';
            if (i < other.number.size())
                sum += other.number[other.number.size() - 1 - i] - '0';
            carry = sum >= 10;
            result.push_back(sum % 10 + '0');
        }

        if (isNegative)
            result.push_back('-');

        std::reverse(result.begin(), result.end());

        return Bigint(result);
    }

    //Вычитание больших чисел
    Bigint operator-(const Bigint& other) const {
        if (isNegative != other.isNegative) {
            if (isNegative)
                return (*this*-1 + other)*-1;
            else
                return *this + (other*-1);
        }

        if (isNegative && *this < other)
            return (other - *this)*-1;

        if (*this < other)
            return (other - *this)*-1;

        std::string result;
        int borrow = 0;

        for (int i = 0; i < number.size(); i++) {
            int diff = number[number.size() - 1 - i] - '0' - borrow;
            if (i < other.number.size()) diff -= other.number[other.number.size() - 1 - i] - '0';
            borrow = diff < 0;
            if (borrow) diff += 10;
            result.push_back(diff + '0');
        }

        while (result.size() > 1 && result.back() == '0')
            result.pop_back();

        if (isNegative)
            result.push_back('-');

        std::reverse(result.begin(), result.end());

        return Bigint(result);
    }

    //Умножение больших чисел
    Bigint operator*(const Bigint& other) const {
        Bigint result;

        result.isNegative = isNegative != other.isNegative;
        result.number.resize(number.size() + other.number.size(), '0');

        for (int i = number.size() - 1; i >= 0; i--) {
            int carry = 0;
            for (int j = other.number.size() - 1; j >= 0; j--) {
                int product = (number[i] - '0') * (other.number[j] - '0') + carry + result.number[i + j + 1] - '0';
                result.number[i + j + 1] = product % 10 + '0';
                carry = product / 10;
            }
            result.number[i] += carry;
        }
        result.removeLeadingZeros();

        return result;
    }

    //Деление больших чисел
    Bigint operator/(const Bigint& other) const {
        Bigint absOther, result, current;
        absOther.number = other.number;
        result.number.resize(number.size());

        for (int i = 0; i < number.size(); i++) {
            current.number.push_back(number[i]);
            current.removeLeadingZeros();
            int x = 0, l = 0, r = 10;
            
            while (l <= r) {
                int m = (l + r) / 2;
                Bigint t = absOther * m;
                if (t < current || t == current) {
                    x = m;
                    l = m + 1;
                } else
                    r = m - 1;
            }

            result.number[i] = x + '0';
            current = current - absOther * x;
        }

        result.removeLeadingZeros();
        result.isNegative = isNegative != other.isNegative;

        return result;
    }

    //Сравнение == больших чисел
    bool operator==(const Bigint& other) const {
        return isNegative == other.isNegative && number == other.number;
    }

    //Сравнение < больших чисел
    bool operator<(const Bigint& other) const {
        if (isNegative != other.isNegative)
            return isNegative;
        if (number.size() != other.number.size())
            return number.size() < other.number.size();
        return (isNegative ? '-' + number : number) < (other.isNegative ? '-' + other.number : other.number);
    }

    //Сравнение > больших чисел
    bool operator>(const Bigint& other) const {
        return !(*this == other || *this < other);
    }

    //Удаление лишних нулей
    void removeLeadingZeros() {
        while (number.size() > 1 && number[0] == '0')
            number.erase(0, 1);
    }

    //Подключаем функцию вывода в консоль больших чисел
    friend std::ostream& operator<<(std::ostream& os, const Bigint& obj);
};

//Вывод в консоль больших чисел
std::ostream& operator<<(std::ostream& os, const Bigint& obj) {
    if (obj.isNegative)
        os << '-';
    os << obj.number;
    return os;
}

int main() {
    std::string a, b;
    std::cin >> a >> b;
    Bigint first(a);
    Bigint second(b);

    std::cout << "a + b = " << (first + second) << std::endl;
    std::cout << "a - b = " << (first - second) << std::endl;
    std::cout << "a * b = " << (first * second) << std::endl;
    std::cout << "a / b = " << (first / second) << std::endl;

    int c;
    std::cin >> c;
    Bigint third(c);
    Bigint zero;

    std::cout << "с > 0 = " << (third > zero) << std::endl;
    std::cout << "с < 0 = " << (third < zero) << std::endl;
    std::cout << "с == 0 = " << (third == zero) << std::endl;

    return 0;
}