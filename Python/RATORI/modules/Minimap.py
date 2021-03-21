import pygame as pg
from modules.Terrain import Terrain


class Minimap(object):

    def __init__(self, size):
        """ Миникарта """
        self.size = size
        self.rate = 48
        self.minimap_size = self.width, self.height = self.calculation()
        self.surface = pg.Surface(self.minimap_size)
        self.rect = pg.Rect((1, self.size[1] - self.height), self.minimap_size)
        self.filling()

    def update(self, e, size):
        """ Обновление миникарты """

        # Перерасчет размера миникарты
        if self.size != size:
            self.size = size
            self.calculation()
            self.filling()

    def draw(self, g):
        """ Отрисовка """
        g.blit(self.surface, self.rect)
        pg.draw.rect(g, 'Black', self.rect, 3)

    def calculation(self):  # ДОДЕЛАТЬ
        """ Перерасчет размеров миникарты """
        self.rate = 48
        width = 320
        height = 180
        return width, height

    def filling(self):  # ДОДЕЛАТЬ
        """ Заполнение миникарты """
        self.surface.set_alpha(192)
        self.surface.fill('Grey')  # Фон за краями карты
        # Заполняем миникарту минитайлами
        """
        for y in range(y_top // self.rate, y_bottom // self.rate + 1):
            for x in range(x_left // self.rate, x_right // self.rate + 1):
                key = self.terrain.tile_map[y][x]
                tile = self.terrain.tile_atlas[key]
                self.surface.blit(tile, (x * self.rate - x_left, y * self.rate - y_top, self.rate, self.rate))
        """
