def solution(string, ending):
    if ending == string[-len(ending):] or ending == "":
        return True
    else:
        return False

# тест для локального запуска
test1 = "abcde"
test2 = "cde"
print(test1, test2, " - тестовые строки")
print(solution(test1, test2), " - проверка совпадения конца строки")
input()