from modules.interface.Minimap import Minimap
from modules.interface.Life import Life
from modules.interface.Score import Score
from modules.interface.Control import Control


class Interface(object):

    def __init__(self, size):
        """ Интерфейс игры """
        self.size = size
        self.life = Life()
        self.score = Score()
        self.control = Control()
        self.minimap = Minimap(self.size)

    def update(self, hero, size):
        """ Обновление интерфейса """
        self.minimap.update(hero, size)

    def draw(self, g):
        """ Отрисовка интерфейса """
        self.minimap.draw(g)
