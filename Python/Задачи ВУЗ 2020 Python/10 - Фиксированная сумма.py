s, l1, r1, l2, r2 = map(int, input("Введите через пробел число и два диапазона чисел (s l1 r1 l2 r2): ").split())

if abs(s) > 1e15 or abs(l1) > 1e15 or abs(r1) > 1e15 or abs(l2) > 1e15 or abs(r2) > 1e15:
    print("Некорректный ввод")
    input()
    quit()

if s < l1 + l2 or s > r1 + r2:
    print(-1)
elif s - l1 <= r2:
    print(l1, s - l1)
else:
    print(s - r2, r2)

input()