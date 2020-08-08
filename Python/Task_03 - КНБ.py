#Камень - ножницы - бумага

import os, random

os.system("mode con cols=60 lines=16")

step = win = lose = draw = 0
game = "             Начнем игру"
user = comp = 0

while True:
    print("Всего:", step, " Побед:", win, " Поражений:", lose, " Ничьих:", draw)
    print("")
    comp = random.randint(0, 2)
    step += 1
    print("     Игрок: ", user, "     Компьютер: ", comp)
    print("")
    print(game)
    print("")
    user = int(input("Камень - 0, ножницы - 1, бумага - 2:  "))
    if user == comp:
        game = "             == НИЧЬЯ =="
        draw += 1
    elif (user == 0 and comp == 1) or (user == 1 and comp == 2) or (user == 2 and comp == 0):
        game = "            !!! ПОБЕДА !!!"
        win += 1
    elif user >= 0 and user <= 2:
        game = "           >> ПОРАЖЕНИЕ <<"
        lose += 1
    else:
        game = "        ... неверный ввод ..."
    os.system('cls||clear')