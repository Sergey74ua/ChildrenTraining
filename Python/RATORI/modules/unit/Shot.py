import pygame as pg
from modules.unit.Abstract import Abstract


class Shot(Abstract):

    def __init__(self, size, turn):
        """ Пуля """
        self.size = size
        self.unit_turn = turn
        self.speed = 6
        self.speedD = 4
        self.point_x = self.size[0] // 2
        self.point_y = self.size[1] // 2

    def update(self, turn):
        """ Обновление координат """
        self.point_x, self.point_y = self.pos_unit(turn)

    def draw(self, g):
        """ Отрисовка пули """
        pg.draw.circle(g, 'Red', (self.point_x, self.point_y), 3)
