def solution(s):
    if len(s) % 2 == 1:
        s += "_"
    arr_s = []
    for i in range(0, len(s), 2):
        s2 = s[i] + s[i+1]
        arr_s.append(s2)
    return arr_s

# тест для локального запуска
test = "1234567"
print(test, " - тестовая строка")
print(solution("1234567"), "- строка разделенная по 2 символа с добавлением \"_\" при необходимости")
input()