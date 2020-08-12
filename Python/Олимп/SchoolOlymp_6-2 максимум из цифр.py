S = input("Введите сумму: ") # текст для локального запуска

S = list(S)

for i in range(len(S)):
    for j in range(i+1, len(S)):
        if S[i] < S[j]:
            S[i], S[j] = S[j], S[i]

print("".join(S), "- максимальное число из цифр") # текст для локального запуска

input() # для локального запуска