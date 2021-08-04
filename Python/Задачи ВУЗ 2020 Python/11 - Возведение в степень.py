x = int(input("Введите число: "))
n = int(input("Введите степень: "))

s = 0
if n != 0:
    s = x
    for i in range(n-1):
        s *= x

print("Результат:", s)

input()