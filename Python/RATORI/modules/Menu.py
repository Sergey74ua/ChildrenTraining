import pygame as pg
from modules.Button import Button


class Menu(object):
    button_name = ['Старт', 'Создать', 'Загурзить', 'Сохранить',
                   'Настройки', 'Об игре', 'Вернуться', 'Выход']

    def __init__(self, size):
        """ Меню """
        self.menu_state = True
        self.size = size
        self.list_button = []
        self.button_action = None
        for i in range(8):
            btn_pos = self.position(i)
            button = Button(btn_pos, self.button_name[i])
            self.list_button.append(button)
        self.list_button[6].active = False  # ВРЕМЕННО

    def update(self, e):
        """ Обновление пунктов меню """
        size = pg.display.get_window_size()

        # Переразмещаем кнопки по центру
        if self.size != size:
            self.size = size
            for i in range(8):
                btn_pos = self.position(i)
                self.list_button[i].rect.x = btn_pos[0]
                self.list_button[i].rect.y = btn_pos[1]

        # Наведение и клики кнопок мышки
        pos = pg.mouse.get_pos()
        click = pg.mouse.get_pressed(3)

        # Определяем состояние кнопки
        for button in self.list_button:
            if button.active and button.rect.collidepoint(pos):
                button.focus = True
                if click[0]:
                    button.pressed = True
                    self.functions(button.name)
                else:
                    button.pressed = False
                    self.button_action = None
            else:
                button.focus = False
            button.update()

        # Клики кнопок клавиатуры (события)
        if e.type == pg.KEYUP and e.key == pg.K_F1:
            print('Нажата F1')
            self.functions(self.button_name[0])

    def draw(self, g):
        """ Отрисовка меню """
        g.fill('SteelBlue')
        for button in self.list_button:
            button.draw(g)

    def position(self, i):
        """ Рассчет позиций кнопок """
        if i < 4:
            pos_x = self.size[0] / 2 - 380
            pos_y = self.size[1] / 2 + i * 100 - 190
        else:
            pos_x = self.size[0] / 2 + 20
            pos_y = self.size[1] / 2 + i * 100 - 590
        return pos_x, pos_y

    def functions(self, button_name):
        """ Функции кнопок """
        if self.button_action != button_name:
            self.button_action = button_name
            if self.button_action == self.button_name[0]:
                print('Нажата кнопка: ', self.button_action)
                self.menu_state = False
            if self.button_action == self.button_name[1]:
                print('Нажата кнопка: ', self.button_action)
            if self.button_action == self.button_name[2]:
                print('Нажата кнопка: ', self.button_action)
            if self.button_action == self.button_name[3]:
                print('Нажата кнопка: ', self.button_action)
            if self.button_action == self.button_name[4]:
                print('Нажата кнопка: ', self.button_action)
            if self.button_action == self.button_name[5]:
                print('Нажата кнопка: ', self.button_action)
            if self.button_action == self.button_name[6]:
                print('Нажата кнопка: ', self.button_action)
            if self.button_action == self.button_name[7]:
                print('Нажата кнопка: ', self.button_action)
                pg.quit()
                quit()