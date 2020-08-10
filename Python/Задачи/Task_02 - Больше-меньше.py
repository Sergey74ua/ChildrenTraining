#Больше - меньше
import os, random

os.system("mode con cols=40 lines=10")

while True:
    os.system('cls||clear')
    x = random.randrange(1000)
    print("Угадайте число до 1'000")
    step = 0
    while True:
        step += 1
        user_x = int(input("Попытка № " + str(step) + ": "))
        if user_x == x:
            print("Вы угадали с ", step, " попыток")
            break
        elif user_x > x:
            print("Перебор ...")
        elif user_x < x:
            print("Недобор ...")
    input()