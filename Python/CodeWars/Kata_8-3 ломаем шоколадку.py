def breakChocolate(n, m):
    if m * n > 0:
        return m * n - 1
    else:
        return 0

# тест для локального запуска
test1 = 5
test2 = 5
print(test1, test2, " - размер шоколадки")
print(breakChocolate(test1, test2), " - колличество сломов")
input()

# а можно короче
# def breakChocolate(n, m):
#     return 0 if n*m==0 else n*m-1

# или еще короче
# def breakChocolate(n, m):
#     return max(m * n - 1, 0)