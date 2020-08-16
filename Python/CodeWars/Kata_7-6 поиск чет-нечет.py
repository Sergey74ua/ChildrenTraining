def iq_test(numbers):
    numbers = numbers.split()
    arr = []
    for i in range(len(numbers)):
        arr.append(int(numbers[i]) % 2)
    
    for i in range(len(arr)):
        if i < len(arr)-1:
            if arr[i] != arr[i+1] and arr[i] != arr[i-1]:
                return i+1
        else:
            if arr[i] != arr[i-1] and arr[i] != arr[i-2]:
                return i+1

# тест для локального запуска
test = "2 4 7 8 10"
print(test, "- массив чисел")
print(iq_test(test), "- уникальный чет/нечет")
input()

# более короткий вариант
# def iq_test(numbers):
#     e = [int(i) % 2 == 0 for i in numbers.split()]
#     return e.index(True) + 1 if e.count(True) == 1 else e.index(False) + 1

# еще более короткий вариант  
# def iq_test(numbers):
#     eo = [int(n)%2 for n in numbers.split()]
#     return eo.index(1 if eo.count(0)>1 else 0)+1