#Площадь и периметр прямоугольного треугольника

import os
import math

os.system("title Площадь и периметр")
os.system("mode con cols=60 lines=16")
os.system("color 0a")

while True:
    os.system('cls||clear')
    print("Рассчет площади и периметра прямоугольного треугольника")
    a = float(input("\nВведите длину первого катета:  "))
    b = float(input("\nВведите длину второго катета:  "))
    c = math.sqrt(a**2 + b**2)
    
    print("\nГипотенуза треугольника равна -", c)
    print("\nПлощадь треугольника равна -", (a * b) / 2)
    print("\nПериметр треугольника равен -", a + b + c)
    
    input()