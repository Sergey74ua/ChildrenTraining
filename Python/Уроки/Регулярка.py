import re

txt='Мама', 'авТо', 'гриБ', 'Яблоко', 'яБлоко', 'ябЛоко', \
    'яблОко', 'яблоКо', 'яблокО', 'агент007', 'стриж', 'ГТО', 'Три богатыря'

for i in txt:
    print(*re.findall(r"^[a-zа-яё]*[A-ZА-ЯЁ]{1}[a-zа-яё]*$", i))