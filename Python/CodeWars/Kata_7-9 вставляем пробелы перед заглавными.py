def solution(s):
    s2 = ""
    for i in s:
        if i == i.upper():
            s2 = s2 + " " + i
        else:
            s2 = s2 + i
    return s2

# тест для локального запуска
test = "helloWorld"
print(test, "- входящая строка")
print(solution(test), "- строка с пробелами")
input()

# более короткий вариант
# def solution(s):
#     return ''.join(' ' + c if c.isupper() else c for c in s)