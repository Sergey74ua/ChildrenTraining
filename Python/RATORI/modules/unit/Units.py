import pygame as pg
from random import randint
from modules.unit.Adapter import Adapter


class Units(object):
    """ Юниты """

    def __init__(self, size, count):
        """ Список юнитов """
        tile_atlas = Adapter.filling()
        self.size = size
        self.list_unit = []
        self.count = count
        for i in range(self.count):
            unit = Adapter(size, tile_atlas)
            self.list_unit.append(unit)
        self.unit_speed = 3
        self.unit_speed_d = 2

    def update(self, turn, speed):
        """ Обновление юнтов """
        for unit in self.list_unit:
            if not unit.arrest:
                if unit.rect.collidepoint(self.size[0] // 2, self.size[1] // 2):
                    unit.arrest = True
                elif unit.time_move < 1:
                    unit.time_move = randint(30, 150)
                    unit.unit_turn = randint(0, 8)
                unit.time_move -= 1
                self.move_unit(unit)
            unit.update(turn, speed)

    def draw(self, g):
        """ Отрисовка юнитов """
        for unit in self.list_unit:
            unit.draw(g)

    def move_unit(self, unit):
        """ Движение юнита """
        if unit.unit_turn == 1:
            unit.point_x += self.unit_speed_d
            unit.point_y += self.unit_speed_d
        elif unit.unit_turn == 7:
            unit.point_x -= self.unit_speed_d
            unit.point_y += self.unit_speed_d
        elif unit.unit_turn == 5:
            unit.point_x -= self.unit_speed_d
            unit.point_y -= self.unit_speed_d
        elif unit.unit_turn == 3:
            unit.point_x += self.unit_speed_d
            unit.point_y -= self.unit_speed_d
        elif unit.unit_turn == 2:
            unit.point_x += self.unit_speed
        elif unit.unit_turn == 0:
            unit.point_y += self.unit_speed
        elif unit.unit_turn == 6:
            unit.point_x -= self.unit_speed
        elif unit.unit_turn == 4:
            unit.point_y -= self.unit_speed

        return unit.point_x, unit.point_y
