from random import randint


class Units:
    """Базовый класс"""
    def __init__(self, file):
        self.file = file
        self.pos = self.get_pos()

    @staticmethod
    def get_pos():
        return randint(50, 430), randint(50, 270)
