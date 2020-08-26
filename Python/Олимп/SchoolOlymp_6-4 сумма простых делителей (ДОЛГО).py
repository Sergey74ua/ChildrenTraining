x = int(input("Введите число: ")) # текст для локального запуска

def test_num(num):
    arr = []
    for i in range(3, num // 2 + 1, 2):
        if num % (i) == 0:
            arr.append(i)
    return arr

all_test = test_num(x)
all_test.append(x)
if x % 2 == 0:
    all_test.append(2)
print(all_test) # просмотр для локального запуска

n = 0
for i in all_test:
    if len(test_num(i)) == 0:
        n += 1
        print(" -", i, end = "") # просмотр для локального запуска
print(" - ") # для локального запуска

print(n)

input() # для локального запуска




# ********************   ДОЛГО ВЫПОЛНЯЕТСЯ   ********************