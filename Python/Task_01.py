#Високосные года
import os

while True:
    x = int(input("Введите год: "))
    os.system('cls' if os.name == 'nt' else 'clear')
    if x % 4 == 0 and x % 100 != 0 or x % 400 == 0:
        print(x, "год - високосный")
    else:
        print(x, "год - не високосный")