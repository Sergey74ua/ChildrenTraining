import pygame as pg
from modules.Menu import Menu
from modules.Game import Game


class Main(object):
    _image_ = pg.image.load("images/icon.bmp")

    def __init__(self):
        """ Программа """
        self.game_version = 1
        self.flag = int(pg.RESIZABLE)
        self.size = self.width, self.height = 1280, 720
        self.fps = 60
        pg.display.set_mode(self.size, self.flag)
        pg.display.set_icon(self._image_)
        pg.display.set_caption("RATORI")

    def game_start(self):
        """ Новая игра """
        self.speed = 50  # до 100
        self.menu = Menu(self.size)
        self.game = Game(self.size, self.speed)
        self.game_cycle()

    def game_cycle(self):
        """ Цикл обновления кадров """
        g = pg.display.get_surface()
        while self.game.game_state:

            # Проверка событий
            for e in pg.event.get():

                # Выход из игры
                if e.type == pg.QUIT:
                    pg.quit()
                    quit()

                # Полноэкранный режим (ИСПРАВИТЬ ПЕРЕХОД ИЗ ПОЛНОЭКРАННОГО РЕЖИМА)
                if (e.type == pg.KEYDOWN and (e.key == pg.K_F11 or
                        (e.key == pg.K_RETURN and e.mod == pg.KMOD_LALT))):  # НЕ РАБОТАЕТ
                    if g.get_flags() & pg.FULLSCREEN:
                        self.flag = pg.RESIZABLE
                    else:
                        self.flag = pg.FULLSCREEN
                    pg.display.set_mode((self.width, self.height), self.flag)

                # Изменение размера окна (ДОПИСАТЬ ПЕРЕРАСЧЕТ МАСШТАБА, ЕСЛИ НАДО И СОХРАНЕНИЕ НАСТРОЕК)
                if e.type == pg.VIDEORESIZE:
                    print(g.get_width(), g.get_height())  # УДАЛИТЬ
                    pg.display.update()

                # Переключение паузы / игры
                if e.type == pg.KEYDOWN and e.key == pg.K_ESCAPE:
                    self.menu.menu_state = not self.menu.menu_state

            # Трансляция событий в Меню / Игру
            if self.menu.menu_state == True:
                self.menu.update(e)
            else:
                self.game.update(e)

            # Отрисовка Меню / Игры
            if self.menu.menu_state:
                self.menu.draw(g)
            else:
                self.game.draw(g)

            pg.display.flip()
            pg.time.Clock().tick(self.fps)

        self.game_ower()

    def game_over(self):   # (ДОПИСАТЬ ЗАПРОС НА СОХРАНЕНИЕ)
        """ Выход из игры """
        self.menu_state = True

    def __del__(self):  # (ДОПИСАТЬ ЗАПРОС НА СОХРАНЕНИЕ ИГРЫ)
        """ Выход из программы """
        print('выход')
