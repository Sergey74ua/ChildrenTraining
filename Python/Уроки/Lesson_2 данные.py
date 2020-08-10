# Урок № 1 по Python

# строковые и числовые данные
print("1+2+3+4+5")
print(1+2+3+4+5)
print("")

x = "5.0"
print(x)
print("строка = " + x)
print("")

x = 5
print(x)
print("число =", str(x)) # вывод нескольких строк
print("число = " + str(x)) # конкатенация (слияние строк)
print("")

# типы данных
x = True
print(x)
print(type(x))

x = 5
print(x)
print(type(x))

x = 5.0
print(x)
print(type(x))
print("")

x = 3.9e3
print(x) # 3900.0

x = 3.9e-3
print(x) # 0.0039
print("")

# разновидности деления
print(7 / 2)  # 3.5
print(7 // 2) # 3
print(7 % 2)  # остаток от деления - 1
print("")

# возведение в квадрат
print(5 ** 2)  # 5 в квадрате - 25
print("")

# сокращение действий
x = 10
x += 5
print(x) # 15
print("")

# преобразование типа данных
x = "2"
y = 3
z = int(x) + y
print(z) # 5
print("")

# системы измерений
x2 = 0b101 # 5
x8 = 0o11  # 9
x16 = 0x0a # 10
x = x2 + x8 + x16 # 24
print("десятичная система - {0}, бинарная - {0:08b}, 8-ричная - {0:02x}, 16-ричная - {0:02o}".format(x))
print("")

input()