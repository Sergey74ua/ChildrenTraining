/* Дано арифметическое выражение, которое может состоять из:
    бинарных, левоассоциативных операторов: +, -, *, /, %
    бинарного, правоассоциативного оператора: возведение в степень (^)
    неотрицательных операндов целого типа
    скобочек: ( и ).
Преобразуйте это выражение в обратную польскую нотацию.
Формат ввода
В одной строке задано арифметическое выражение (без пробелов). В конце строки символ \n.
Формат вывода
Выражение преобразованное в обратную польскую нотацию. Между элементами должно быть по одному пробелу.

Пример 1
Ввод	Вывод
1+2+3
1 2 + 3 +
Пример 2
Ввод	Вывод
2^3^4
2 3 4 ^ ^
Пример 3
Ввод	Вывод
2^3*(4+5)-6/71
2 3 ^ 4 5 + * 6 71 / -
*/

#include <iostream> 
#include <stack> 
#include <string> 

int getPriority(char operation)
{
    if (operation == '+' || operation == '-')
        return 1;
    else if (operation == '*' || operation == '/' || operation == '%')
        return 2;
    else if (operation == '^')
        return 3;

    return 0;
}

int main()
{
    std::string expression, answer;
    std::stack<char> operators;

    std::getline(std::cin, expression);

    for (char c : expression) {
        if (std::isdigit(c))
            answer += c;
        else if (c == '(')
            operators.push(c);
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                answer += " ";
                answer += operators.top();
                operators.pop();
            }
            operators.pop();
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^') {
            while (!operators.empty() && (getPriority(operators.top()) > getPriority(c)
                || (getPriority(operators.top()) == getPriority(c) && c != '^'))) {
                answer += " ";
                answer += operators.top();
                operators.pop();
            }
            answer += " ";
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        answer += " ";
        answer += operators.top();
        operators.pop();
    }

    std::cout << answer << std::endl;
}