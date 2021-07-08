import pygame as pg
from random import randint


class Gangster(object):
    """ Противник """

    @staticmethod
    def filling():
        """ Заполняем набор тайлов """
        pg.init()
        atlas = pg.image.load('images/gangster.png')
        atlas = pg.transform.scale(atlas, (8 * 80, 9 * 65))
        tile_atlas = []
        rate_x = 80
        rate_y = 65
        for row in range(9):
            tile_atlas.append([])
            for col in range(8):
                rect = (rate_x * col, rate_y * row)
                image = atlas.subsurface(rect, (rate_x, rate_y))
                tile_atlas[row].append(image)
        return tile_atlas

    def __init__(self, size, tile_atlas):
        """ Персонаж противника """
        self.rate_x = 80
        self.rate_y = 65
        self.tile_atlas = tile_atlas
        self.row = 6
        self.col = 0
        self.step = 0
        self.unit_turn = 8
        self.time_move = randint(15, 60)
        self.point_x = randint(size[0]//2-size[0]//3, size[0]//2+size[0]//3)
        self.point_y = randint(size[1]//2-size[1]//3, size[1]//2+size[1]//3)
        self.image = self.tile_atlas[self.row][self.col]
        self.rect = pg.Rect(self.point_x, self.point_y, self.rate_x, self.rate_y)
        self.scroll = 4
        self.scroll_d = round(self.scroll / 1.4)
        self.arrest = False

    def update(self, turn, speed):
        """ Обновление персонажа """
        self.rect.x, self.rect.y = self.pos_unit(turn)
        if self.arrest:
            self.image = self.tile_atlas[8][self.col]
        elif self.unit_turn == 8:
            self.image = self.tile_atlas[6][0]
        else:
            self.col = self.unit_turn
            self.image = self.select(speed)

    def draw_unit(self, g):
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
        return self.point_x, self.point_y
