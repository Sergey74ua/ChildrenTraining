x = int(input("Введите число: "))

if x < 0 or x > 1e15:
    print("Некорректный ввод")
    input()
    quit()

s = 0
if x != 0:
    n = 1
    while n <= x:
        n *= 2
        s += 1

print("Количество степеней двойки:", s)

input()