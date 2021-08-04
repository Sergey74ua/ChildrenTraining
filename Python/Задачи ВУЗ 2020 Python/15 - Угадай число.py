import random
from random import randrange

g = "1"
while g == "1":
    n = randrange(100)
    print("Угадайте число до 100: ")
    
    s = 0
    while True:
        s += 1
        x = int(input())
        if x == n:
            print("Поздравляю! Вы угадали")
            break
        
        elif x > n:
            print("Загаданное число меньше")
        else:
            print("Загаданное число больше")
        
        if s == 5:
            print("Вы проиграли. Было загадано:", n)
            break

    g = input("Хотите начать сначала? (1 - ДА ): ")
    print()
    continue