def alphabet_position(text):
    text = list(text.lower())
    arr = []
    for i in text:
        temp = ord(i)-96
        if 0 < temp < 27:
            arr.append(str(temp))
    return " ".join(arr)

# тест для локального запуска
test = "The sunset sets at twelve o' clock."
# "20 8 5 19 21 14 19 5 20 19 5 20 19 1 20 20 23 5 12 22 5 15 3 12 15 3 11"
print(test, "- строка")
print(alphabet_position(test), "- позиции букв")
input()

# более корректный вариант
# def alphabet_position(text):
#     return " ".join(str(ord(c)-ord("a")+1) for c in s.lower() if c.isalpha())
