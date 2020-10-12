A, act, B = input("Введите арифметическое действие через пробел: ").split()
A = float(A)
B = float(B)

if act == "+":
    print(A + B)
elif act == "-":
    print(A - B)
elif act == "*":
    print(A - B)
elif act == "/":
    print(A / B)
else:
    print("неопределенное действие")

input()