# Урок № 2 по Python

# логические операции
x = True
y = False
print(x == y)  # False - x не равно y
print("")

# операции сравнения
x = 5
y = 6
R = 5 == 6     # сохраняем результат операции в переменную
print(R)       # False - 5 не равно 6
print(type(R)) # тип данных
print("")

print(x != y)  # True
print(x > y)   # False
print(x <= y)  # True
print("")

# and, or, not
print(x > 0 and y > 0) # True
print(x < 0 or y < 0)  # False
print(not x == y)      # True
print("")

# if, elif, else
x = 20
if x > 0:
    print("число " + str(x) + " больше 0")
    if x == 20:
        print("а точнее, число равно 20 (вложенное уловие)")
elif x == 0:
    print("число равно 0", str(x))
else:
    print("число меньше 0", str(x))
print("")

if 15 < x < 25:
    print("сравнение двойного условия", str(x))
print("")

input()