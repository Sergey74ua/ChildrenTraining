#Високосные года
import os

os.system("mode con cols=25 lines=3")

while True:
    x = int(input("Введите год: "))
    os.system('cls||clear')
    if x % 4 == 0 and x % 100 != 0 or x % 400 == 0:
        print(x, "год - високосный")
    else:
        print(x, "год - не високосный")