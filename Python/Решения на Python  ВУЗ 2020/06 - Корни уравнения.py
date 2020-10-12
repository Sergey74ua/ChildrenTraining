a = float(input("Введите число a: "))
b = float(input("Введите число b: "))
c = float(input("Введите число c: "))

d = b ** 2 - 4 * a * c

if a == 0:
    print("один корень: ", -c / b)
elif d > 0:
    print("первый корень: ", (-b + (d ** 0.5)) / (2 * a))
    print("второй корень: ", (-b - (d ** 0.5)) / (2 * a))
elif d == 0:
    print("один корень: ", -b / (2 * a))
else:
    print("корней нет")

input()