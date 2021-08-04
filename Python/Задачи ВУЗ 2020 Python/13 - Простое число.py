n = int(input("Введите число: "))

if n < 2 or n > 1e9:
    print("Некорректный ввод")
    input()
    quit()

s = 0
for i in range(1, n + 1):
    if n % i == 0:
        s += 1

if s == 2:
    print("Простое число")
else:
    print("Составное число")

input()