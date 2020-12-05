import eel

def start():
    eel.init("web")

    @eel.expose
    def call_in_js():
        pass

    eel.start("index.html", size=(400, 300))