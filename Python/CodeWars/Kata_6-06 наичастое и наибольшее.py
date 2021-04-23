def highest_rank(arr):
    num = 0
    sum = 0
    for i in arr:
        if arr.count(i) > sum:
            sum = arr.count(i)
            num = i
        if arr.count(i) == sum and i >= num:
            sum = arr.count(i)
            num = i
    return num


# тест для локального запуска
test = [12, 10, 8, 8, 3, 3, 3, 3, 2, 4, 10, 12, 10]
print(test, "- начальный текст")
print(highest_rank(test), "- наичастое и наибольшее число из массива")
input()

# highest_rank([12, 10, 8, 12, 7, 6, 4, 10, 12]) - 12
# highest_rank([12, 10, 8, 12, 7, 6, 4, 10, 10]) - 10

# более короткий вариант
# def highest_rank(arr):
#    return max(sorted(arr,reverse=True), key=arr.count)