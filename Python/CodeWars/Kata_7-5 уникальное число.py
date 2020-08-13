def find_uniq(arr):
    for i in range(len(arr)):
        if i < len(arr)-1:
            if arr[i] != arr[i+1] and arr[i] != arr[i-1]:
                return arr[i]
        else:
            if arr[i] != arr[i-1] and arr[i] != arr[i-2]:
                return arr[i]

# тест для локального запуска
test = [ 0, 0, 0.55, 0, 0 ]
print(test, "- массив чисел")
print(find_uniq(test), "- уникальное число")
input()

# более короткий вариант
# def find_uniq(arr):
#     a = sorted(arr)
#     return a[0] if a[0] != a[1] else a[-1]

# еще один короткий вариант
# def find_uniq(arr):
#     a, b = set(arr)
#     return a if arr.count(a) == 1 else b

# и еще более короткий вариант
# def find_uniq(arr):
#     return [x for x in set(arr) if arr.count(x) == 1][0]