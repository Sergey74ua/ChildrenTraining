# Урок № 3 по Python

import random

# цикл while
x = 0
while x < 5:
    x += 1
    print(x)
print("")

# цикл for вариации: (stop) / (start, stop) / (start, stop, step)
for i in range(10):
    print(i, end=" ")
print("\n")

for i in "цикл":
    print(i, end=" ")
print("\n")

for i in range(100, 111):
    print(i, end=" ")
print("\n")

# вложенные циклы
for i in range(1000, 2222, 88):
    for j in range(30, -31, -6):
        print(i, j, end=" ")
    print("")
print("")

# бесконечный цикл + break / continue
while True:
    print("Случайное число: ", str(random.randint(1, 101)))
    x = input("Продолжть - 0, закончить - 1\n")
    if x == "0":
        print("продолжаем ...\n")
        continue # перезапуск цикла
    elif x == "1":
        print("игра окончена\n")
        break # выход из цикла
    else:
        print("неизвестный ввод")

# рандомы
print("random 0.0-1.0 : ", str(random.random()), "\n")
print("randint 50-500 : ", str(random.randint(50, 500)), "\n")
print("randrange до 20 : ", str(random.randrange(20)), "\n")
print("randrange 40-80 : ", str(random.randrange(40, 80)), "\n")
print("randrange 90-180/3 : ", str(random.randrange(90, 180, 3)), "\n")
print("")

x = [11, 22, 33, 44, 55, 66, 77, 88, 99]
print("берем список : ", x)
random.shuffle(x)
print("перетосовка shuffle : ", x)  
print("случайный выбор choice : ", random.choice(x))
print("")

input()