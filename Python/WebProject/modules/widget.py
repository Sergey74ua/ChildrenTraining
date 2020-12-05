import eel

def start():
    eel.init("web")

    #Прием сообщения по пути: html - JavaScript - Python
    @eel.expose
    def call_in_js(msg):
        print(msg)

    #Отправка сообщения по пути: Python - JavaScript - html
    eel.call_in_python("Hello from Python!")

    eel.start("index.html", mode="chrome" ,size=(400, 300))
    #mode=(chrome, edge, opera, electron, custom, None, False ...)