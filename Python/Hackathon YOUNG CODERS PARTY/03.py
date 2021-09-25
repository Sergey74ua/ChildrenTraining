N = int(input())
F1 = 1
F2 = 1

for i in range(N-1):
    F = F1 + F2
    F2 = F1
    F1 = F

print(F)


#Дорешивание