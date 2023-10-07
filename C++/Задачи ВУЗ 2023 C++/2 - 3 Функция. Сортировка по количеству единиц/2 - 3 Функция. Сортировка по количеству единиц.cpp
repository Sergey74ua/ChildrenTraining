/* Дан код, который получает последовательность целых положительных чисел, состоящих из единиц и нулей(без ведущих нулей)и сортирует
её по убыванию количества единиц в числе.Числа, с одинаковым количеством единиц, должны быть отсортированы по возрастанию значения
Формат ввода
В первой строке входных данных указано количество чисел в последовательности 1 ≤ n ≤ 1000.
Во второй строке входных данных указано n чисел состоящих только из нулей и единиц 1 ≤ a i ≤ 1111111111. Числа разделены пробелами.
Формат вывода
Отсортированная последовательность чисел, через пробел.
Пример 1
Ввод	Вывод
4
1000000 100001 10101 1111
1111 10101 100001 1000000
Пример 2
Ввод	Вывод
4
111 11000 10001 100
111 10001 11000 100
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

bool compare(const std::string& a, const std::string& b) {
    int count_a = 0;
    int count_b = 0;

    for (char c : a)
        if (c == '1')
            count_a++;

    for (char c : b)
        if (c == '1')
            count_b++;

    if (count_a > count_b)
        return true;
    else if (count_a < count_b)
        return false;
    else if (count_a == count_b) {
        if (a.length() > b.length())
            return false;
        else if (a.length() < b.length())
            return true;
        else if (a.length() == b.length()) {
            if (a.find('0') >= b.find('0'))
                return false;
            else
                return true;
        }
    }
}

int main() {
    int count;
    std::cin >> count;

    std::vector<std::string> nums(count);
    for (auto& line : nums) std::cin >> line;

    std::sort(nums.begin(), nums.end(), compare);

    for (auto& line : nums) std::cout << line << ' ';
}