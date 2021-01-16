import sys
import keyboard
import pyautogui
from PySide2 import QtWidgets
from Form import Ui_Form

if __name__ == '__main__':
    app = QtWidgets.QApplication(sys.argv)

    form = QtWidgets.QMainWindow()
    ui_Form = Ui_Form()
    ui_Form.setupUi(form)
    form.show()

    pyautogui.PAUSE = 0.5

    def click_CLICK():
        click = 0
        while not keyboard.is_pressed('Esc'):
            pyautogui.click()
            click += 1
            ui_Form.click_sum.setText(str(click))
            print("число кликов: ", click)

    def click_POS():
        pos = pyautogui.position()
        ui_Form.pos_X.setText(str(pos.x))
        ui_Form.pos_Y.setText(str(pos.y))

    # ПРОБЛЕМА !!! Клик срабатывает несколько раз и столько же запускат функцию
    # >>> решение из меню РАТОРИ не подходит, там проверяется "and" движение мышки
    ui_Form.GET_CLICK.clicked.connect(click_CLICK)
    ui_Form.GET_POS.clicked.connect(click_POS)

    # Вывод названий нажатых клавиш
    def print_pressed_keys(e):
        print(e, e.event_type, e.name)
        ui_Form.key_name.setText(str(e.name))
    keyboard.hook(print_pressed_keys)

    sys.exit(app.exec_())
