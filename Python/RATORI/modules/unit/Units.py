import pygame as pg
from random import randint
from modules.unit.Gangster import Gangster


class Units(object):
    """ Юниты """

    def __init__(self, size, count):
        """ Список юнитов """
        self.list_unit = []
        self.count = count
        for i in range(self.count):
            unit = Gangster(size)
            self.list_unit.append(unit)
        self.unit_speed = 3
        self.unit_speed_d = 2

    def update(self, turn, speed):
        """ Обновление юнтов """
        for i in range(self.count):
            if self.list_unit[i].time_move < 1:
                self.list_unit[i].time_move = randint(30, 150)
                self.list_unit[i].unit_turn = randint(0, 8)
            self.list_unit[i].time_move -= 1
            self.list_unit[i].update(turn, speed)
            self.move_unit(self.list_unit[i])

    def draw(self, g):
        """ Отрисовка юнитов """
        for i in range(self.count):
            self.list_unit[i].draw(g)

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
