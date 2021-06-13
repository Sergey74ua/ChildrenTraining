from modules.interface.Minimap import Minimap
from modules.interface.Life import Life
from modules.interface.Score import Score
from modules.interface.Control import Control


class Interface(object):

    def __init__(self, size):
        """ Интерфейс игры """
        self.size = size
        self.minimap = Minimap(self.size)
        self.life = Life()
        self.score = Score(size)
        self.control = Control(size)

    def update(self, hero, size):
        """ Обновление интерфейса """
        self.minimap.update(hero, size)
        self.life.update()
        self.score.update(size)
        self.control.update(size)

    def draw(self, g):
        """ Отрисовка интерфейса """
        self.minimap.draw(g)
        self.life.draw(g)
        self.score.draw(g)
        self.control.draw(g)
