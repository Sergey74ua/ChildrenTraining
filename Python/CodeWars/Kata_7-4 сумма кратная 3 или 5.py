def solution(number):
    sum = 0
    for i in range(number):
        if i % 3 == 0 or i % 5 == 0:
            sum += i
    return sum

# тест для локального запуска
test = 23
print(test, "- предел ряда чисел")
print(solution(test), "- сумма кратных 3 или 5")
input()

# более короткий вариант
# def solution(number):
#    return sum(x for x in range(number) if x % 3 == 0 or x % 5 == 0)