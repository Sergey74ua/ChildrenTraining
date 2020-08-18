def generate_hashtag(s):
    if s == "" or len(s) > 139:
        return False
    else:
        s = s.split()
        for i in range(len(s)):
            s[i] = s[i].title()
    s = "#" + "".join(s)
    return s

# тест для локального запуска
test = "codewars is nice"
print(test, "- входящая строка")
print(generate_hashtag(test), "- ХешТег")
input()

# более короткий вариант
# def generate_hashtag(s):
#     ans = '#'+ str(s.title().replace(' ',''))
#     return s and not len(ans)>140 and ans or False

# еще более короткий вариант
# def generate_hashtag(s): return '#' +s.strip().title().replace(' ','') if 0<len(s)<=140 else False