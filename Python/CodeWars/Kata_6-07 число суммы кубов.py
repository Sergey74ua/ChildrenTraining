def find_nb(m):
    cube = 0
    sum = 0
    while m > sum:
        cube += 1
        sum = sum + (cube * cube * cube)
    if sum != m:
        cube = -1
    return cube


# тест для локального запуска
test = 4183059834009
print(test, "- требуемый объем")
print(find_nb(test), "- число кубов для достижения объема")
input()

# find_nb(4183059834009) - 2022
# find_nb(24723578342962) - -1
# find_nb(135440716410000) - 4824
# find_nb(40539911473216) - 3568
# find_nb(26825883955641) - 3218

# более короткий вариант
# def find_nb(m):
#    a = int((2*m**0.5)**0.5)
#    if (a*(a+1)/2)**2 == m:
#        return a
#    return -1