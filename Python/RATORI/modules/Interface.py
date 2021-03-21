from modules.Minimap import Minimap


class Interface(object):

    def __init__(self, size):
        """ Интерфейс игры """
        self.size = size
        self.minimap = Minimap(self.size)
        # табло жизней
        # табло очков
        # кнопки управления

    def update(self, hero, size):
        """ Обновление интерфейса """
        self.minimap.update(hero, size)

    def draw(self, g):
        """ Отрисовка интерфейса """
        self.minimap.draw(g)
