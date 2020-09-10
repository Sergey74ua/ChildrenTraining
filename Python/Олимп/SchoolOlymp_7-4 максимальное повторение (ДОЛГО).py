N = input("Введите диапазон номеров: ") # текст для локального запуска
M = int(input("Сколько всего номеров в списке: ")) # текст для локального запуска
arr = input("Введите список через пробел: ") # текст для локального запуска

arr = list(map(int, arr.split()))
sumN = 0
maxN = 0

for i in range(M):
    temp = arr.count(arr[i])
    if temp > sumN:
        sumN = temp
        maxN = arr[i]
    elif temp == sumN and maxN > arr[i]:
        maxN = arr[i]

print(maxN, sumN)

input() # для локального запуска