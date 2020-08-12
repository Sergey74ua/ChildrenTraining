def to_weird_case(string):
    string = list(string)
    StRiNg = ""
    pos = 0
    for i in string:
        pos += 1
        if i == " ":
            StRiNg += i
            pos = 0
        elif pos % 2 == 0:
            StRiNg += i.lower()
        else:
            StRiNg += i.upper()
    return StRiNg

# тест для локального запуска
test = "Qwer ty Uiop asdf Ghjkl zxcv"
print(test, "- начальный текст")
print(to_weird_case(test), "- с чередованием регистра букв")
input()