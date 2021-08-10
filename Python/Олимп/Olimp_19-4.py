N = int(input())

arr1 = []
arr2 = []

for i in range(N):
    arr = input()
    for j in range(N):
        if (i + j) % 2 == 0:
            arr1.append(arr[j])
        else:
            arr2.append(arr[j])

def maximum(arr):
    arr.sort()
    
    max_counter = 0
    last = 0
    
    for i in arr:
        pass
    
    for i in arr:
        if i != last:
            counter = 1
            last = i
        else:
            counter += 1
            if counter > max_counter:
                last_counter = max_counter # ПРЕДЫДУЩИЙ СЧЕТЧИК, А НЕ КОЛИЧЕСТВО
                max_counter = counter
                max_symbol = i

    return max_symbol, max_counter, last_counter
    
max_symbol_1, max_counter_1, last_counter_1 = maximum(arr1)
max_symbol_2, max_counter_2, last_counter_2 = maximum(arr2)

if max_symbol_1 != max_symbol_2:
    rez = (len(arr1) - max_counter_1) + (len(arr2) - max_counter_2)
else:
    rez_1 = (len(arr1) - max_counter_1) + (len(arr2) - last_counter_2)
    rez_2 = (len(arr1) - last_counter_1) + (len(arr2) - max_counter_2)
    if rez_1 < rez_2:
        rez = rez_1
    else:
        rez = rez_2

print(rez)