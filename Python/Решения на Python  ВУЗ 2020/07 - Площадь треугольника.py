print("Выберите способ ввода параметров треугольника:")
print("1. Длины сторон")
print("2. Координаты вершин")

while True:
    form = int(input())
    if abs(form) > 1000:
        quit()
    
    if form == 1:
        a = float(input("Введите сторону a: "))
        b = float(input("Введите сторону b: "))
        c = float(input("Введите сторону c: "))
        break
    
    elif form == 2:
        xA, yA = map(float, input("Введите вершины A через пробел: ").split())
        xB, yB = map(float, input("Введите вершины B через пробел: ").split())
        xC, yC = map(float, input("Введите вершины C через пробел: ").split())
        a = ((xB - xA) ** 2 + (yB - yA) ** 2) ** 0.5
        b = ((xC - xA) ** 2 + (yC - yA) ** 2) ** 0.5
        c = ((xB - xC) ** 2 + (yB - yC) ** 2) ** 0.5
        break
    
    else:
        print("ошибочный ввод")
        continue

if a > b + c or b > a + c or c > a + b:
    print("Некорректные данные")
else:
    P = (a + b + c) / 2
    S = (P * (P - a) * (P - b) * (P - c)) ** 0.5
    print("S =", S)

input()