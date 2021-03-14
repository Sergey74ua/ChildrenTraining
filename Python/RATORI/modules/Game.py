import pygame as pg
from modules.Ground import Ground
from modules.Hero import Hero


class Game(object):

    def __init__(self, size, speed):
        """ Игра """
        self.game_state = True
        self.size = size
        self.speed = speed
        self.ground = Ground(size)
        self.hero = Hero()
        self.hero.rect.center = self.position(size)
        self.turn = 'stop'

    def update(self, e):
        """ Обновление игры """
        size = pg.display.get_window_size()  # Переразмещаем элементы в окне
        if self.size != size:
            self.size = size
            self.hero.rect.center = self.position(size)

        # Список кликов кнопок клавиатуры
        keys = pg.key.get_pressed()
        if (keys[pg.K_RIGHT] and keys[pg.K_DOWN]) or (keys[pg.K_d] and keys[pg.K_s]):
            self.turn = 'right_down'
        elif (keys[pg.K_LEFT] and keys[pg.K_DOWN]) or (keys[pg.K_a] and keys[pg.K_s]):
            self.turn = 'left_down'
        elif (keys[pg.K_LEFT] and keys[pg.K_UP]) or (keys[pg.K_a] and keys[pg.K_w]):
            self.turn = 'left_up'
        elif (keys[pg.K_RIGHT] and keys[pg.K_UP]) or (keys[pg.K_d] and keys[pg.K_w]):
            self.turn = 'right_up'
        elif keys[pg.K_RIGHT] or keys[pg.K_d]:
            self.turn = 'right'
        elif keys[pg.K_DOWN] or keys[pg.K_s]:
            self.turn = 'down'
        elif keys[pg.K_LEFT] or keys[pg.K_a]:
            self.turn = 'left'
        elif keys[pg.K_UP] or keys[pg.K_w]:
            self.turn = 'up'
        else:
            self.turn = 'stop'

        # Клики кнопок мышки (события)
        if e.type == pg.MOUSEBUTTONUP:
            if e.button == 1:
                #print("Нажата кнопка № ", e.button, " в позиции ", pg.mouse.get_pos())
                pass
            elif e.button == 2:
                #print("Нажата кнопка № ", e.button, " в позиции ", pg.mouse.get_pos())
                pass

        self.ground.update(self.turn, self.speed)
        self.hero.update(self.turn, self.speed)

    def draw(self, g):
        """ Отрисовка игры """
        g.fill('Grey')
        self.ground.draw(g)
        self.hero.draw(g)

    def position(self, size):  # РАСШИРИТЬ ДЛЯ ЭЛЕМЕНТОВ УПРАВЛЕНИЯ
        """ Перерассчет позиций """
        pos_x = size[0] // 2
        pos_y = size[1] // 2
        return pos_x, pos_y
