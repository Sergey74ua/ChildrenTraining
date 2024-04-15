__author__ = "Maxim"

from datetime import datetime

from model.json.settings import Json
from model.sql.dataBase import Sqlite
from model.socket.socket import Socket

class Model():
    def __init__(self):
        self.json = Json()
        #self.sql = Sqlite() # Загатовка для сохранения чата и т.д.
        #self.socket = Socket() # Исправить потоки
        self.name = "undefined"
        self.chat = ["temp"]

# t = datetime.now().strftime("%H:%M:%S")