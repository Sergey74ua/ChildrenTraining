#Камень - ножницы - бумага

import os, random

os.system("title КНБ")
os.system("mode con cols=50 lines=10")
os.system("color 0a")

step = win = lose = draw = 0
user = comp = 3
name = ["Камень", "Ножницы", "Бумага", "......"]
game = "             Начнем игру"

while True:
    print("")
    print(" Всего:", step, " Побед:", win, " Поражений:", lose, " Ничьих:", draw)
    print("")
    print("    Игрок: ", name[user], "     Компьютер: ", name[comp])
    print("")
    print(game)
    print("")
    user = int(input(" Камень - 0, ножницы - 1, бумага - 2:   "))
    comp = random.randint(0, 2)
    step += 1
    if user == comp:
        game = "              == НИЧЬЯ =="
        draw += 1
    elif (user == 0 and comp == 1) or (user == 1 and comp == 2) or (user == 2 and comp == 0):
        game = "             !!! ПОБЕДА !!!"
        win += 1
    elif user >= 0 and user <= 2:
        game = "            >> ПОРАЖЕНИЕ <<"
        lose += 1
    else:
        game = "         ... неверный ввод ..."
    os.system('cls||clear')