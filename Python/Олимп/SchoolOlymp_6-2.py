while True:
    S = input("Введите сумму: ")
    Smax = list(S)
    for i in range(len(S)):
        for j in range(i+1, len(S)):
            if int(S[j]) > int(S[i]):
                Smax[j], Smax[i] = Smax[i], Smax[j]
    S = "".join(Smax)
    print(int(S))
input() # для локального запуска

# ******** сбой при повторе цифр ********