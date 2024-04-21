import sys
#import animations
from os import getcwd
from PySide6.QtGui import QGuiApplication
from PySide6.QtWidgets import QApplication, QWidget
from PySide6.QtQml import QQmlApplicationEngine
from PySide6.QtWidgets import QWidget, QGraphicsOpacityEffect
from PySide6.QtCore import QPropertyAnimation, QParallelAnimationGroup, QPoint
appPath = getcwd() + "\\src\\app\\"

if __name__ == "__main__":
    app = QGuiApplication(sys.argv)
    engine = QQmlApplicationEngine()
    qml_file = appPath + "authorization.qml"
    engine.load(qml_file)
    if not engine.rootObjects():
        sys.exit(-1)
    sys.exit(app.exec())