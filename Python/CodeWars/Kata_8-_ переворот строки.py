def spin_words(sentence):
    sentence = list(sentence)
    for i in range(len(sentence) // 2):
        sentence[i], sentence[-i - 1] = sentence[-i - 1], sentence[i]
    return "".join(sentence)

# тест для локального запуска
test = "Hello world!"
print(test, " - тестовая строка")
print(spin_words(test), " - перевернутая строка")
input()

# а можно короче
# def spin_words(sentence):
#     return "".join(reversed(sentence))

# или еще короче
# def spin_words(sentence):
#     return sentence[::-1]