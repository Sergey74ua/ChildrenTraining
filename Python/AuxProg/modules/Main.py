import sys
import mouse
import keyboard
import pyautogui as a
from PySide2 import QtCore, QtWidgets
from modules.Ui_Form import Ui_Form
from time import sleep

class Main(Ui_Form, QtWidgets.QWidget):
    """Автокликкер с наследованием от ui-формы"""
    def __init__(self):
        super().__init__()
        self.click_x = "X"
        self.click_y = "Y"
        self.click_symbol = "Q"
        self.click_tempo = 10
        self.setupUi(self)
        self.installEventFilter(self)
        self.show()
        # Сигналы - слоты
        self.button_status = False
        self.start.clicked.connect(self.button_click)
        self.exit.clicked.connect(self.close)
        self.tempo.editingFinished.connect(self.set_tempo)
        self.timer = QtCore.QTimer(self)
        self.timer.setInterval(self.click_tempo)
        self.timer.timeout.connect(self.auto_click)
        keyboard.hook(self.print_pressed_keys)
        #pyautogui.PAUSE = 0.5

    def eventFilter(self, source, e):
        """Позиция на экране (Qt)"""
        if e.type() == QtCore.QEvent.MouseButtonPress:
            self.offset = e.pos()
            return False
        elif e.type() == QtCore.QEvent.MouseMove and self.offset is not None:
            self.move(self.pos() - self.offset + e.pos())
            self.pos_x.setText(str(self.x()+39))
            self.pos_y.setText(str(self.y()+62))
            return True
        else:
            return False

    #def keyPressEvent(self, e):  # Функционирует только при активности окна
    #    """Отображение нажатой клавиши (Qt)"""
    #    if e.key():
    #        self.symbol.setText(str(chr(e.key())))  # Проблема с небуквенными символами
    #        if e.key() == 81 or e.key() == 1049:
    #            self.button_click()
    #    e.accept()

    def print_pressed_keys(self, e):
        """Вывод нажатых клавиш (keyboard)"""
        print(e, e.event_type, e.name)
        self.symbol.setText(str(e.name))
        if e.name == "q" and e.event_type == "down":  # Проблемный timer.start/stop нажим/отпуск и en/ру
            self.button_click()

    def button_click(self):
        """Событие клика по кнопке (Qt)"""
        self.button_status = not self.button_status
        if self.button_status:
            self.start.setText("Pause")
            a.moveTo(self.x()+32, self.y()+62)
            self.timer.start()
        else:
            self.timer.stop()
            self.start.setText("Start")
            self.start.setFocus()

    def set_tempo(self):
        """Установка темпа (Qt)"""
        self.click_tempo = int(self.tempo.text())
        self.start.setFocus()

    def auto_click(self):
        """Собственно, автокликкер (PyAutoGUI)"""
        if self.button_status:
            #print(a.position())
            #a.tripleClick()
            #sleep(0.01)
            mouse.click(button="left")
            mouse.click(button="left")
            mouse.click(button="left")
            #mouse.double_click(button="left")

    """
    def mousePressEvent(self, e):
        self.pos_x.setText(str(e.globalX()))
        self.pos_y.setText(str(e.globalY()))

    def mouseMoveEvent(self, e):
        self.pos_x.setText(str(e.x()))
        self.pos_y.setText(str(e.y()))
    """