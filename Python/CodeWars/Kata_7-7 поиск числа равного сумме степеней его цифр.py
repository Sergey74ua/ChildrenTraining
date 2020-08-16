def sum_dig_pow(a, b):
    arr = []
    for i in range(a, b+1):
        temp = list(str(i))
        summ = 0
        for j in range(len(temp)):
            summ += int(temp[j]) ** (j+1)
        if i == summ:
            arr.append(i)
    return arr

# тест для локального запуска
test1 = 0
test2 = 135
print(test1, test2, "- массив чисел")
print(sum_dig_pow(test1, test2), "- числа равные сумме степеней его цифр")
input()

# более короткий вариант
# def sum_dig_pow(a, b):
#     return [x for x in range(a, b+1) if sum(int(d)**i for i, d in enumerate(str(x), 1)) == x]

# еще более короткий вариант
# sum_dig_pow=lambda a,b:[n for n in range(a,b+1) if sum(long(x)**(i+1) for i,x in enumerate(str(n)))==n]