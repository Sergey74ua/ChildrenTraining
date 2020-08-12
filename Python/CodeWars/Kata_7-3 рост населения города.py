def nb_year(p0, percent, aug, p):
    years = 0
    while p0 < p:
        years += 1
        p0 = p0 + round(p0*percent/100) + aug
    return years

# тест для локального запуска
test1 = 1000
test2 = 2.0
test3 = 50
test4 = 1200
print(test1, test2, test3, test4, "- население, прирост %, миграция +, предел")
print(nb_year(test1, test2, test3, test4), "- срок роста населения")
input()

# более короткий вариант
# def nb_year(p0, percent, aug, p, years = 0):
#     if p0 < p:
#         return nb_year(p0 + int(p0 * percent / 100) + aug, percent, aug, p, years + 1)
#     return years