# Урок № 10 по Python - конвертация типов данных  INT / STR

# INT  -  INT  -  INT
def INT_INT_INT(x):
    print("Ввод: ", x, " - тип данных:", type(x))
    res = x * 2
    return res
res = INT_INT_INT(100)
print("Вывод:", res, " - тип данных:", type(res))
print()

# STR  -  STR  -  STR
x = "200"
print("Ввод: ", x, " - тип данных:", type(x))
res = x * 2
print("Вывод:", res, " - тип данных:", type(res))
print()

# INT  -  INT  -  STR
x = 380
print("Ввод:  ", x, "  - тип данных: ", type(x))
res = str(x // 10) + " попугаев"
print("Вывод: ", res, "  - тип данных: ", type(res))
print()

# INT  -  STR  -  STR
x = 123
print("Ввод:  ", x, "  - тип данных: ", type(x))
res = str(123)[::-1]
print("Вывод: ", res, "  - тип данных: ", type(res))
print()

# INT  -  STR  -  INT
x = 123
print("Ввод:  ", x, "  - тип данных: ", type(x))
res = int(str(x)[::-1])
print("Вывод: ", res, "  - тип данных: ", type(res))
print()

# STR  -  STR  -  INT
x = "12345"
print("Ввод:  ", x, "  - тип данных: ", type(x))
res = int(x) * 2
print("Вывод: ", res, "  - тип данных: ", type(res))
print()

# STR  -  INT  -  STR

# STR  -  INT  -  INT

input()