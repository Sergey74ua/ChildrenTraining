def productFib(prod):
    n1 = 0
    n2 = 1
    mult = 0
    res = False
    while mult < prod:
        temp = n1 + n2
        n1 = n2
        n2 = temp
        mult = n1 * n2
    if mult == prod:
        res = True
    return [n1, n2, res]


# тест для локального запуска
test = 5895
print(test, "- проверяемое число")
print(productFib(test), "- числа Фибоначи, произведение которых дает это число")
input()

# productFib(4895) - [55, 89, True]
# productFib(5895) - [89, 144, False]

# более короткий вариант
# def productFib(prod):
#  a, b = 0, 1
#  while prod > a * b:
#    a, b = b, a + b
#  return [a, b, prod == a * b]

# совсем короткий вариант
# def productFib(prod, f1=0, f2=1):
#    return [f1, f2, True] if prod == f1 * f2 else [f1, f2, False] if prod < f1 * f2 else productFib(prod, f2, f1+f2)