__author__ = "Maxim"

from PySide6.QtWidgets import QWidget
from PySide6.QtCore import Slot, Signal

from datetime import datetime

from view.message import Ui_message

class Message(QWidget):

    def __init__(self, parent=None):
        super(Message, self).__init__(parent)
        self.ui = Ui_message()
        self.ui.setupUi(self)
        self.time = datetime.now().strftime("%H:%M:%S")
        self.ui.timeLabel.setText(str(self.time)) # Время будет с модели
