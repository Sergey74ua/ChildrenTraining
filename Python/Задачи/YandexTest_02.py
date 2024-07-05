# Даны два строковых представления чисел A и B. Нужно максимизировать A, заменив
# в нём любую цифру на цифру из B. Каждую цифру B можно использовать только один раз.

def aMaxB(a, b):
    a = list(map(int, a))
    b = list(map(int, b))
    b.sort(reverse=True)
    for i in range(len(a)):
        for j in range(len(b)):
            if a[i] < b[j]:
                a[i], b[j] = b[j], 0
    a = int(''.join(map(str, a)))
    return a

# пример для теста функции
a, b = '1923', '1456' # тут будет 6954
print(aMaxB(a, b))

# Сложность будет - O(n^2), т.к. циклы перебирает 2 массива, каждый с каждым.
