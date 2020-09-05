N = int(input("Введите число тестов (1-10): ")) # текст для локального запуска
arr = []
for i in range(N):
    A = int(input("Введите число " + str(i+1) + ": ")) # текст для локального запуска
    if A <= 100 or (A - 100) % 7 != 0:
        arr.append(-1)
    else:
        arr.append((A - 100) // 7)

for i in arr:
    print(i)

input() # для локального запуска