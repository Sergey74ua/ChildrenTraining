# Пример запуска

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