# Установка библиотек:
# pip install pygame
# pip install pyside2
# designer.exe в папках библиотек
# pyside2-uic in.ui -o out.py

# В gitignore добавляем папку venv
# Сохраняем список библиотек:
# pip freeze > requirements.txt
# Установка библиотек по списку:
# pip install -r requirements.txt

from modules import game

import sys
from PySide2 import QtWidgets, QtGui, QtCore
from out import Ui_Form

if __name__ == '__main__':
    app = QtWidgets.QApplication(sys.argv)
    Dialog = QtWidgets.QDialog()
    form = Ui_Form()
    form.setupUi(Dialog)
    Dialog.show()

    game.game_cycle()