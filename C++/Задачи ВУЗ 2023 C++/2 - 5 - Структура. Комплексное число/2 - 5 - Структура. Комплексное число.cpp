/*Даны два комплексных числа. Вычислите для них: сумму, разность, произведение и частное
Этот код будет прогоняться по тестам. Ваша задача реализовать функции make_complex, sum, sub, mul, div и print таким образом, чтобы код стал рабочим.

Функция make_complex принимает на вход строку и создаёт по ней структуру Complex. В строке комплексное число задано в виде действительной и мнимой
части именно в таком порядке. Действительная и мнимая части - вещественные числа. После мнимой части стоит символ j. Указанные компоненты числа могут
быть разделены любым количеством пробелов:
0 - 6j
9 + 0j
26 +12j
-1.2 - 5.6 j
 0 -0j
Функция sum вычисляет сумму двух комплексных чисел.
Функция sub вычисляет разность двух комплексных чисел.
Функция mul вычисляет произведение двух комплексных чисел.
Функция div вычисляет частное двух комплексных чисел.
Функция print выводит на экран комплексное число. Вывод осуществляется без пробелов, в следующем порядке: сначала действительная часть, затем мнимая.
После мнимой части выводится символ j. Даже если какая-то из частей равна нулю, она всё равно выводится:

0-6j
9+0j
26+12j
-1.2-5.6j
Формат ввода
Два комплексных числа разделённые пробелом. Каждое число состоит из действительной и мнимой части именно в таком порядке. Действительная и мнимая части
- вещественные числа. После мнимой части стоит символ j. Указанные компоненты числа могут быть разделены любым количеством пробелов. Гарантируется, что
второе комплексное число не равно нулю:


0 - 6j
9 + 0j
26 +12j
-1.2 - 5.6 j
 0 -0j
Формат вывода
Четыре комплексных числа на 4х строках в порядке: сумма, разность, произведение, частное. Вывод комплексных чисел осуществляется без пробелов, в следующем
порядке: сначала действительная часть, затем мнимая. После мнимой части выводится символ j. Даже если какая-то из частей равна нулю, она всё равно выводится.

Пример 1
Ввод	Вывод
1 + 2j 1 + 2j
2+4j
0+0j
-3+4j
1+0j
Пример 2
Ввод	Вывод
0+0j 1-2j
1-2j
-1+2j
0+0j
0+0j
*/

#include <iostream>

struct Complex {
    double re;  // Действительная часть
    double im;  // Мнимая часть
};

#include <string>

Complex make_complex(std::string num) {
    bool is_minus = false;
    bool is_plus = false;
    std::string first;
    std::string second;
    for (char c : num) {
        if (c == '-') {
            is_minus = true;
            continue;

        }
        else if (c == '+') {
            is_plus = true;
            continue;
        }
        if (!(is_plus || is_minus) && c != ' ') {
            first += c;
        }
        else if ((is_plus || is_minus) && c != ' ') {
            if (first.length() == 0) {
                first += '-';
                first += c;
                is_minus = false;
                continue;
            }
            second += c;
        }
    }
    double re = std::stod(first);
    double im = std::stod(second);
    if (is_minus) {
        im *= -1;
    }
    Complex complex;
    complex.re = re;
    complex.im = im;
    return complex;

}

Complex sum(Complex left, Complex right) {
    double f = left.re + right.re;
    double s = left.im + right.im;
    if (left.im + right.im == 0) {
        s = 0.;
    }
    return Complex{ f,s };
}

Complex sub(Complex left, Complex right) {
    return Complex{ left.re - right.re, left.im - right.im };
}

Complex mul(Complex left, Complex right) {
    double f = left.re * right.re - left.im * right.im;
    double s = left.re * right.im + left.im * right.re;
    return Complex{ f,s };
}

Complex div(Complex left, Complex right) {
    return Complex{
        (left.re * right.re + left.im * right.im) / (right.re * right.re + right.im * right.im),
        (left.im * right.re - left.re * right.im) / (right.re * right.re + right.im * right.im) };
}

void print(Complex num) {
    double re, im;
    re = num.re;
    im = num.im;
    std::cout << re;
    if (im >= 0) {
        std::cout << "+";
    }
    std::cout << im << "j\n";
}

int main()
{
    std::string num;
    std::getline(std::cin, num, 'j');
    Complex c1 = make_complex(num);

    std::getline(std::cin, num, 'j');
    Complex c2 = make_complex(num);

    print(sum(c1, c2));
    print(sub(c1, c2));
    print(mul(c1, c2));
    print(div(c1, c2));
}