import pygame as pg
from modules.Terrain import Terrain


class Minimap(object):

    def __init__(self, size):
        """ Миникарта """
        self.size = size
        self.terrain = Terrain()
        self.count_x = len(self.terrain.tile_map[0])
        self.count_y = len(self.terrain.tile_map)
        self.rate = self.terrain.rate
        self.rect = self.calculation()
        self.surface = pg.Surface((self.rect.width, self.rect.height))
        self.hero = self.position(self.terrain.start_point)
        self.filling()

    def update(self, hero, size):
        """ Обновление миникарты """

        # Перерасчет размера миникарты
        if self.size != size:
            self.size = size
            self.rect = self.calculation()
            self.surface = pg.Surface((self.rect.width, self.rect.height))
            self.filling()

        # Обновления позиции персонажа на миникарте
        self.hero = self.position(hero)

    def draw(self, g):
        """ Отрисовка """
        g.blit(self.surface, self.rect)
        pg.draw.circle(g, 'Blue', self.hero, 5)
        pg.draw.rect(g, 'Black', self.rect, 3)

    def calculation(self):
        """ Перерасчет размеров миникарты """
        if self.count_x > self.count_y:  # ДОДЕЛАТЬ масштабируемость
            self.rate = self.size[0] // (self.count_x * 3)
        else:
            self.rate = self.size[1] // (self.count_y * 3)
        width = self.count_x * self.rate
        height = self.count_y * self.rate
        rect = pg.Rect(1, self.size[1] - height - 1, width, height)
        return rect

    def position(self, hero):
        """ Перерасчет позиции героя """
        hero_x = hero[0] * self.rate // self.terrain.rate
        hero_y = self.size[1] - self.rect.height + hero[1] * self.rate // self.terrain.rate
        return hero_x, hero_y

    def filling(self):
        """ Заполнение миникарты """
        self.surface.set_alpha(207)
        self.surface.fill('Grey')  # Фон за краями карты
        # Заполняем миникарту минитайлами
        for y in range(self.count_y):
            for x in range(self.count_x):
                key = self.terrain.tile_map[y][x]
                tile = self.terrain.tile_atlas[key]
                self.surface.blit(tile, (x * self.rate, y * self.rate, self.rate, self.rate))
