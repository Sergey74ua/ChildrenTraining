# ВТОРОЙ ВАРИАНТ
def justify(text, width):
    text_out = []
    string = []
    length = 0
    
    for word in text.split():
        len_word = len(word)
        if length + len_word <= width:
            string.append(word)
            length += len_word + 1
        else:
            begin = len(string) - 1
            end = width - length + 1
            if begin > 0:
                i = 0
                for j in range(end):
                    string[i] += ' '
                    if i < begin - 1:
                        i += 1
                    else:
                        i = 0
                text_out.append(' '.join(string))
            else:
                text_out += string
            string = [word, ]
            length = len_word + 1

    if length == 0:
        text_out.append(string)
    else:
        text_out.append(' '.join(string))

    return '\n'.join(text_out)


# тест для локального запуска
test = '123 456 123 45 6 1 23 456 123 45 6 123 456 1 23 45 6 123 45 6 12 3 456 123 45 6 123 45 6'
print("Текстовая строка:")
print(test)
print("\nВыровненная строка:")
print(justify(test, 7))
input()

# justify('123 45 6', 7) - '123  45\n6'
