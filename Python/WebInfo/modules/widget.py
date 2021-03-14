import eel

import os
from random import randint
from datetime import datetime

def start():
    eel.init("web")

    # Прием сообщения по пути: html - JavaScript - Python
    @eel.expose
    def call_in_js(msg_in):
        print(msg_in)
        if msg_in == 'quit':
            os.system("TASKKILL /F /IM Chrome.exe")
            quit()
        elif msg_in.isdigit():
            msg_out = int(msg_in)**2
        elif msg_in == 'time':
            msg_out = str(datetime.now())
        elif msg_in == 'random':
            msg_out = randint(0, 100)
        elif msg_in == 'paint':
            msg_out = 'Запускаем MS Paint'
            os.system('C:/Windows/system32/mspaint.exe')
        elif msg_in == 'calk':
            msg_out = 'Запускаем Калькулятор'
            os.system('F:/SOFT/Office/Калькулятор.exe')
        elif msg_in == 'notepad':
            msg_out = 'Запускаем Блокнот'
            os.system('%windir%/system32/notepad.exe')
        elif msg_in == 'tc':
            msg_out = 'Запускаем Total Commander'
            os.system('"C:/Program Files/totalcmd/TOTALCMD64.EXE"')
        elif msg_in == 'exp':
            msg_out = 'Запускаем Проводник'
            os.system('C:/Windows/explorer.exe')
        elif msg_in == 'opera':
            msg_out = 'Запускаем Opera'
            os.startfile('C:/Users/Администратор/AppData/Local/Programs/Opera/launcher.exe')
        elif msg_in == 'np':
            msg_out = 'Запускаем Notepad++'
            os.startfile('C:/Program Files (x86)/Notepad++/notepad++.exe')
        else:
            msg_out = "От Python: " + msg_in
        call_in_python(msg_out)

    # Отправка сообщения по пути: Python - JavaScript - html
    def call_in_python(msg_out):
        eel.call_in_python(msg_out)

    # Веб-интерфейс
    eel.start("index.html", mode="chrome", size=(720, 400))
    # mode=(chrome, edge, opera, electron, custom, None, False ...)
