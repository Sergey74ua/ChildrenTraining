def find_missing(sequence):
    if abs(sequence[1] - sequence[0]) <= abs(sequence[-1] - sequence[-2]):
        step = sequence[1] - sequence[0]
    else:
        sequence[-1] - sequence[-2]
    for i in range(len(sequence)-1):
        if sequence[i] + step != sequence[i+1]:
            return sequence[i]+step

# тест для локального запуска
test = [1, 3, 4, 5, 6, 7, 8, 9]
print(test, "- массив чисел")
print(find_missing(test), "- недостающее число в прогрессии")
input()

# более короткий вариант
# def find_missing(sequence):
#     t = sequence
#     return (t[0] + t[-1]) * (len(t) + 1) / 2 - sum(t)

# еще более короткий вариант
# def find_missing(sequence):
#     return (sequence[-1] + sequence[0]) * (len(sequence) + 1) / 2 - sum(sequence)
