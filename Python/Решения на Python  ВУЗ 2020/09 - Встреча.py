h1, m1 = map(int, input("Введите первое время (чч:мм): ").split(":"))
h2, m2 = map(int, input("Введите второе время (чч:мм): ").split(":"))

if h1 < 0 or h1 > 23 or h2 < 0 or h2 > 23 or m1 < 0 or m1 > 59 or m2 < 0 or m2 > 59:
    print("Некорректный ввод")
    input()
    quit()

if h1 == 23 and h2 == 0:
    h2 += 24;
period = abs((h2 * 60 + m2) - (h1 * 60 + m1))

if period <= 15:
    print("Встреча состоится")
else:
    print("Встреча не состоится")

input()