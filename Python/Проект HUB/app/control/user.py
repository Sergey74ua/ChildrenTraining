__author__ = "Maxim"

from PySide6.QtWidgets import QWidget
from PySide6.QtCore import Slot, Signal

from view.user import Ui_user

class User(QWidget):
    delete = Signal(int)

    def __init__(self, id_widget: int, parent=None):
        super(User, self).__init__(parent)
        self.ui = Ui_user()
        self.ui.setupUi(self)
        self.id_widget = id_widget
        self.ui.userID.setTitle(str(id_widget))

    @Slot()
    def press_del(self):
        self.delete.emit(self.id_widget)