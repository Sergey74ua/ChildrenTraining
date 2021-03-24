import pygame as pg
from modules.ground.Terrain import Terrain


class Ground(object):
    """ Участок карты в окне игры """

    def __init__(self, size):
        """ Карта """
        self.size = size
        self.surface = pg.Surface(self.size)
        self.rect = self.surface.get_rect()
        self.terrain = Terrain()
        self.rate = self.terrain.rate
        self.max_x = len(self.terrain.map[0]) * self.rate
        self.max_y = len(self.terrain.map) * self.rate
        self.tile_x, self.tile_y = self.terrain.start_point

    def update(self, size, turn, speed):
        """ Обновление позиции на карте """

        # Перерасчитываем центр
        if self.size != size:
            self.size = size

        # Прокрутка карты
        scroll = round(speed/(100/(6-1)))+1  # ДОРАБОТАТЬ
        if turn == 'right_down':
            self.tile_x += scroll
            self.tile_y += scroll
        elif turn == 'left_down':
            self.tile_x -= scroll
            self.tile_y += scroll
        elif turn == 'left_up':
            self.tile_x -= scroll
            self.tile_y -= scroll
        elif turn == 'right_up':
            self.tile_x += scroll
            self.tile_y -= scroll
        elif turn == 'right':
            self.tile_x += scroll
        elif turn == 'down':
            self.tile_y += scroll
        elif turn == 'left':
            self.tile_x -= scroll
        elif turn == 'up':
            self.tile_y -= scroll
        self.select()

        # Ограничение краями карты
        if self.tile_x < self.size[0] // 2 + scroll:
            self.tile_x = self.size[0] // 2 + scroll
        if self.tile_x >= self.max_x - self.size[0] // 2 - scroll - 1:
            self.tile_x = self.max_x - self.size[0] // 2 - scroll - 1
        if self.tile_y < self.size[1] // 2 + scroll:
            self.tile_y = self.size[1] // 2 + scroll
        if self.tile_y >= self.max_y - self.size[1] // 2 - scroll - 1:
            self.tile_y = self.max_y - self.size[1] // 2 - scroll - 1

    def draw(self, g):
        """ Отрисовка карты """
        g.fill('Grey')  # Фон для выхода за предел карты
        g.blit(self.surface, self.rect)

    def select(self):
        """ Отрисовка фрейма """
        x_left = self.tile_x - self.size[0] // 2
        x_right = x_left + self.size[0]
        y_top = self.tile_y - self.size[1] // 2
        y_bottom = y_top + self.size[1]

        # Заполняем окно тайлами (желательно обрезать крайние тайлы)
        for y in range(y_top//self.rate, y_bottom//self.rate+1):
            for x in range(x_left//self.rate, x_right//self.rate+1):
                key = self.terrain.map[y][x]  # ОШИБКА за краями карты при расширении экрана
                tile = self.terrain.tile_atlas[key]
                self.surface.blit(tile, (x*self.rate-x_left, y*self.rate-y_top, self.rate, self.rate))
                """
                # НОМЕРА ТАЙЛОВ (тормозят fps)
                pg.font.init()
                font = pg.font.SysFont(None, 14, True)
                text_button = font.render(str(y)+'-'+str(x), True, 'DarkBlue')
                text_rect = text_button.get_rect()
                self.surface.blit(text_button, (x*self.rate-x_left+4, y*self.rate-y_top+16), text_rect)
                """
