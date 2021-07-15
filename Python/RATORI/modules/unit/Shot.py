import pygame as pg


class Shot(object):

    def __init__(self, size, position):
        """ Пуля """
        self.size = size
        self.point_x = self.size[0] // 2
        self.point_y = self.size[1] // 2
        self.position = [self.point_x, self.point_y]
        self.unit_turn = 0

    def update(self, turn):
        """ Обновление координат """
        self.position[0] += 3
        self.position[1] += 2

    def draw(self, g):
        """ Отрисовка пули """
        pg.draw.circle(g, 'Red', (self.position[0], self.position[1]), 3)
