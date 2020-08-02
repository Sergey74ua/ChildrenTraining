#Запуск программ на Python

print("Hello world\n" + '\tновая строка')
print(1+2+3+4+5)

summ = 20.0
if summ > 0:
    print("сумма = " + str(summ))
print("тест отступа")

input()

# Запуск с консоли без патча: D:\Documents\Program\Python>"C:\Program Files (x86)\Python38-32\python.exe" HW.py
# Запуск с консоли с патчем: D:\Documents\Program\Python>python HW.py
# Запуск в браузере на сайте https://ideone.com/
# Запуск с Visual Studio при добавлении компонента Python

# Установка компилятора с консоли: pip install pyinstaller
# Апгрейд pip если надо: C:\Users\Администратор>python -m pip install --upgrade pip
# Компиляция D:\Documents\Program\Python>pyinstaller -f HWplus.py (-f в один файл, -w для графики, -i "путь к иконке" с иконкой)