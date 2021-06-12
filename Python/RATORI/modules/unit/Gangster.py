import pygame as pg


class Gangster(object):
    """ Противник """
    pg.init()
    _atlas_ = pg.image.load('images/gangster.png')
    _atlas_ = pg.transform.scale(_atlas_, (8 * 128, 9 * 104))  # ВРЕМЕННО

    def __init__(self):
        """ Персонаж противника """
        self.rate_x = 128
        self.rate_y = 104
        self.tile_atlas = []
        self.tile_atlas = self.filling()
        self.row = 6
        self.col = 0
        self.step = 0
        self.image = self.tile_atlas[self.row][self.col]
        self.rect = (200, 200, self.rate_x, self.rate_y)
        print(self.rect)

    def update(self, speed):
        """ Обновление персонажа """
        #self.rect = 0
        turn = 'right'
        if turn == 'stop':
            self.image = self.tile_atlas[7][0]
        else:
            if turn == 'right_down':
                self.col = 1
            elif turn == 'left_down':
                self.col = 7
            elif turn == 'left_up':
                self.col = 5
            elif turn == 'right_up':
                self.col = 3
            elif turn == 'right':
                self.col = 2
            elif turn == 'down':
                self.col = 0
            elif turn == 'left':
                self.col = 6
            elif turn == 'up':
                self.col = 4
            self.image = self.select(speed)

    def draw(self, g):
        """ Отрисовка персонажа """
        g.blit(self.image, self.rect)

    def select(self, speed):
        """ Позиция персонажа """
        step = 48*speed/100  # ДОРАБОТАТЬ
        print(step)
        if self.step > 120:  # ПОДОГНАТЬ ДЛИНУ ШАГА (16 px *2)
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
