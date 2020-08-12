def square_digits(num):
    num = str(num)
    string = ""
    for i in num:
        string += str(int(i) ** 2)
    return int(string)

# тест для локального запуска
test = 12345
print(test, "- тестовое число")
print(square_digits(test), "- возведение в квадрат цифр числа")
input()

# чуть короче
# def square_digits(num):
#     ret = ""
#     for x in str(num):
#         ret += str(int(x)**2)
#     return int(ret)