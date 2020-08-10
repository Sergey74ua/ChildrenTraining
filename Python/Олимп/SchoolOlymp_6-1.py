sA1, sB1, sA2, sB2 = input().split()

A1 = int(sA1)
B1 = int(sB1)
A2 = int(sA2)
B2 = int(sB2)

if A1 > B1:
    N1 = A1
else:
    N1 = B1

if A2 > B2:
    N2 = A2
else:
    N2 = B2

print(N1 + N2)

input() # для локального запуска