def series_sum(n):
    step = 1.0
    sum = 0.0
    for i in range(n):
        sum += 1 / step
        step += 3
    return str(f"{sum:.{2}f}")

# тест для локального запуска
test = 3
print(test, "- число дробей")
print(series_sum(test), "- сумма дробей")
input()

# так короче
# return str("%.2f" % sum)