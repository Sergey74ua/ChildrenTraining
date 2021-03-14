from PySide2.QtCore import *
from PySide2.QtGui import *
from PySide2.QtWidgets import *

class Ui_Form(object):
    """ui-форма с наследованием от класса Qt"""
    def setupUi(self, AutoClicker):
        if not AutoClicker.objectName():
            AutoClicker.setObjectName(u"AutoClicker")
        AutoClicker.setWindowTitle("Form")
        image_target = QPixmap("images/pattern.png")
        form = self.palette()
        form.setBrush(QPalette.Normal, QPalette.Window, QBrush(image_target))
        form.setBrush(QPalette.Inactive, QPalette.Window, QBrush(image_target))
        self.setPalette(form)
        self.setMask(image_target.mask())
        self.offset = None
        self.resize(64, 64)
        self.setWindowOpacity(0.7)
        self.setWindowFlag(Qt.WindowStaysOnTopHint)
        font = QFont()
        font.setKerning(True)
        AutoClicker.setFont(font)
        AutoClicker.setStyleSheet("#start {background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5,"
        "radius:0.5, fx:0.5, fy:0.5, stop:0.670455 rgba(246, 246, 246, 255), stop:1 rgba(255, 255, 255, 0));"
        "border: 1px solid black; border-radius: 6px; font: bold 10pt \"Agency FB\";}"
        "#exit {background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5,"
        "stop: 0.698864 rgba(221, 106, 106, 255), stop:1 rgba(255, 255, 255, 0)); border-radius: 7px;"
        "font: bold 12pt \"Wingdings 2\";}"
        "#symbol {background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5,"
        "stop:0.670455 rgba(246, 246, 246, 255), stop:1 rgba(255, 255, 255, 0)); border: 1px solid darkgreen;"
        "border-radius: 7px; font: bold 10pt \"Courier New\"; color: rgb(0, 85, 0);}"
        "#pos_x, #pos_y {background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5,"
        "fy:0.5, stop:0.670455 rgba(246, 246, 246, 255), stop:1 rgba(255, 255, 255, 0));"
        "color: rgb(0, 0, 72); border-radius: 6px; font: bold 10pt \"Small Fonts\";}"
        "#tempo {border: 1px dotted black; border-radius: 3px; font: bold 10pt \"Small Fonts\";"
        "color: rgb(140, 0, 0);}")
        self.image = QLabel(AutoClicker)
        self.image.setObjectName(u"image")
        self.image.setGeometry(QRect(0, 0, 64, 64))
        self.image.setPixmap(QPixmap(u"image/clicker.png"))
        self.image.setAlignment(Qt.AlignCenter)
        self.pos_x = QLabel(AutoClicker)
        self.pos_x.setObjectName(u"pos_x")
        self.pos_x.setGeometry(QRect(34, 20, 30, 20))
        self.pos_x.setAlignment(Qt.AlignCenter)
        self.pos_x.setText(str(self.click_x))
        self.pos_y = QLabel(AutoClicker)
        self.pos_y.setObjectName(u"pos_y")
        self.pos_y.setGeometry(QRect(18, 38, 30, 20))
        self.pos_y.setAlignment(Qt.AlignCenter)
        self.pos_y.setText(str(self.click_y))
        self.exit = QPushButton(AutoClicker)
        self.exit.setObjectName(u"exit")
        self.exit.setGeometry(QRect(48, 0, 14, 14))
        self.exit.setText("U")
        self.tempo = QLineEdit(AutoClicker)
        self.tempo.setObjectName(u"tempo")
        self.tempo.setGeometry(QRect(1, 22, 24, 16))
        self.tempo.setAlignment(Qt.AlignCenter)
        self.tempo.setText(str(self.click_tempo))
        self.start = QPushButton(AutoClicker)
        self.start.setObjectName(u"start")
        self.start.setGeometry(QRect(16, 0, 32, 18))
        self.start.setText("Start")
        self.symbol = QLabel(AutoClicker)
        self.symbol.setObjectName(u"symbol")
        self.symbol.setGeometry(QRect(1, 1, 14, 14))
        self.symbol.setAlignment(Qt.AlignCenter)
        self.symbol.setText(self.click_symbol)
        QWidget.setTabOrder(self.start, self.tempo)
        QWidget.setTabOrder(self.tempo, self.exit)
        QMetaObject.connectSlotsByName(AutoClicker)
