import pygame as pg
from random import *


class Gangster(object):
    """ Противник """
    pg.init()
    _atlas_ = pg.image.load('images/gangster.png')
    _atlas_ = pg.transform.scale(_atlas_, (8 * 80, 9 * 65))

    def __init__(self):
        """ Персонаж противника """
        self.rate_x = 80
        self.rate_y = 65
        self.tile_atlas = []
        self.tile_atlas = self.filling()
        self.row = 6
        self.col = 0
        self.step = 0
        self.unit_turn = 8
        self.time_move = 60
        self.point_x, self.point_y = (randint(400, 600), randint(200, 400))
        self.image = self.tile_atlas[self.row][self.col]
        self.rect = pg.Rect(self.point_x, self.point_y, self.rate_x, self.rate_y)
        self.scroll = 4
        self.scroll_d = round(self.scroll / 1.4)
        self.unit_speed = 3
        self.unit_speed_d = 2

    def update(self, turn, speed):
        """ Обновление персонажа """
        self.rect.x, self.rect.y = self.pos_unit(turn)
        if self.time_move < 1:
            self.unit_turn = self.rand_move()
        self.time_move -= 1

        if self.unit_turn == 8:
            self.image = self.tile_atlas[6][0]
        else:
            self.col = self.unit_turn
            self.image = self.select(speed)

    def draw(self, g):
        """ Отрисовка персонажа """
        g.blit(self.image, self.rect)

    def select(self, speed):
        """ Позиция персонажа """
        step = 48*speed/100
        if self.step > 120:
            if self.row > 4:
                self.row = 0
            else:
                self.row += 1
                self.step = 0
        else:
            self.step += step
        return self.tile_atlas[self.row][self.col]

    def filling(self):
        """ Заполняем набор тайлов """
        for row in range(9):
            self.tile_atlas.append([])
            for col in range(8):
                rect = (self.rate_x * col, self.rate_y * row)
                size = self.rate_x, self.rate_y
                image = self._atlas_.subsurface(rect, size)
                self.tile_atlas[row].append(image)
        return self.tile_atlas

    def pos_unit(self, turn):
        """ Рассчет позиции юнита """
        if turn == 'right_down':
            self.point_x -= self.scroll_d
            self.point_y -= self.scroll_d
        elif turn == 'left_down':
            self.point_x += self.scroll_d
            self.point_y -= self.scroll_d
        elif turn == 'left_up':
            self.point_x += self.scroll_d
            self.point_y += self.scroll_d
        elif turn == 'right_up':
            self.point_x -= self.scroll_d
            self.point_y += self.scroll_d
        elif turn == 'right':
            self.point_x -= self.scroll
        elif turn == 'down':
            self.point_y -= self.scroll
        elif turn == 'left':
            self.point_x += self.scroll
        elif turn == 'up':
            self.point_y += self.scroll

        # Движение юнита
        if self.unit_turn == 1:
            self.point_x += self.unit_speed_d
            self.point_y += self.unit_speed_d
        elif self.unit_turn == 7:
            self.point_x -= self.unit_speed_d
            self.point_y += self.unit_speed_d
        elif self.unit_turn == 5:
            self.point_x -= self.unit_speed_d
            self.point_y -= self.unit_speed_d
        elif self.unit_turn == 3:
            self.point_x += self.unit_speed_d
            self.point_y -= self.unit_speed_d
        elif self.unit_turn == 2:
            self.point_x += self.unit_speed
        elif self.unit_turn == 0:
            self.point_y += self.unit_speed
        elif self.unit_turn == 6:
            self.point_x -= self.unit_speed
        elif self.unit_turn == 4:
            self.point_y -= self.unit_speed

        return self.point_x, self.point_y

    def rand_move(self):
        """ Случайное движение юнита """
        self.time_move = randint(30, 150)
        self.unit_turn = randint(0, 8)

        return self.unit_turn
