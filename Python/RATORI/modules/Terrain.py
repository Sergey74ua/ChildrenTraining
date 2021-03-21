import pygame as pg
from modules.map import map


class Terrain(object):

    _atlas_ = pg.image.load('images/sprite.bmp')
    _atlas_.set_colorkey((255, 255, 255))

    def __init__(self):
        """ Графический атлас (graphic atlas / tile) """
        self.rate = 48
        self.tile_map = map
        self.tile_atlas = self.filling(self.rate)
        self.start_point = 1536, 768  # ЕСЛИ УЧЕСТЬ СМЕЩЕНИЕ НА СЕРЕДИНУ БЛОКА (1511, 743)

    def filling(self, rate):
        """ Заполняем набор тайлов """
        tile_atlas = {}
        for row in range(16):
            for col in range(16):
                rect = (rate * col, rate * row)
                size = (rate, rate)
                image = self._atlas_.subsurface(rect, size)
                key = str(f'{row:0{2}}') + str(f'{col:0{2}}')
                tile_atlas[key] = image
        return tile_atlas
