from random import randint


class Units:
    """Базовый класс"""

    def __init__(self, file):
        self.file = file
        self.pos = self.rnd_pos()

    def console(self):
        print('Юнит рассы: ', self.__class__.__name__, ', на позиции: ', self.pos)

    @staticmethod
    def rnd_pos():
        return randint(50, 430), randint(50, 270)
