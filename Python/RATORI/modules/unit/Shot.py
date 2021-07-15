import pygame as pg


class Shot(object):

    def __init__(self, size, target):
        """ Пуля """
        self.size = size
        self.point_x = self.size[0] // 2
        self.point_y = self.size[1] // 2

    def update(self):
        """ Обновление координат """
        self.point_x += 3
        self.point_y += 2

    def draw(self, g):
        """ Отрисовка пули """
        pg.draw.circle(g, 'Red', (self.point_x, self.point_y), 3)
