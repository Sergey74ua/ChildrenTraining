N = input("Введите диапазон номеров: ") # текст для локального запуска
M = int(input("Сколько всего номеров в списке: ")) # текст для локального запуска
arr = input("Введите список через пробел: ") # текст для локального запуска

arr = list(map(int, arr.split())) #или генератором arr = [int(i) for i in arr.split()]

setArr = set(arr)
sumN = 0
maxN = 0

for i in setArr:
    temp = arr.count(i)
    if temp > sumN:
        sumN = temp
        maxN = i
    elif temp == sumN and maxN > i:
        maxN = i

print(maxN, sumN)

input() # для локального запуска