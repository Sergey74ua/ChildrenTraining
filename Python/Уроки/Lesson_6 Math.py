# Урок № 6 по Python

import math

print("Число Пи", math.pi)
print("экспонента", math.e)

# возведение числа 2 в степень 3
print(math.pow(2, 3))  # 8 (2**3)

# остаток от деления
print(math.fmod(7, 3))  # 1 (7//3)

X = 5
# проверка на число
print(math.isfinite(X))  # True
# проверка на бесконечность
print(math.isinf(X))  # False

# возвращает мантиссу и экспоненту числа
print(math.frexp(3.14))  # (0.785, 2)

# квадратный корень
print(math.sqrt(9))  # 3

# возвращает модуль
print(math.fabs(-20))  # 20

# модуль числа X, а знак от числа Y
print(math.copysign(-10, 1))  # 10

# возвращает дробную и целую часть числа
print(math.modf(123.456))  # (0.45600000000000307, 123.0)

# ближайшее наибольшее целое число
print(math.ceil(4.56))  # 5

# усекает значение до целого
print(math.trunc(3.56))  # 4

# ближайшее наименьшее целое число
print(math.floor(4.56))  # 4

# перевод из радиан в градусы
print(math.degrees(3.14159))  # 180

# перевод из градусов в радианы
print(math.radians(180))   # 3.1415.....

# косинус
print(math.cos(math.radians(60)))   # 0.5
# cинус
print(math.sin(math.radians(90)))   # 1.0
# тангенс
print(math.tan(math.radians(0)))    # 0.0

# гипотенуза
print(math.hypot(3, 4))   # 5.0

# логарифмы
print(math.log(8,2))    # 3.0
print(math.log10(100))    # 2.0

input()