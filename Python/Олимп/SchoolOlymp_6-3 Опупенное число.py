n = int(input("Введите номер: ")) # текст для локального запуска
if n < 4:
    print(1)
else:
    step = 3
    arr = [1, 1, 1]
    while step != n:
        step += 1
        sum = arr[0] + arr[1] + arr[2]
        if step == n:
            print(sum, "- опупенное число по номеру") # текст для локального запуска
            break
        else:
            arr[0] = arr[1]
            arr[1] = arr[2]
            arr[2] = sum

input() # для локального запуска