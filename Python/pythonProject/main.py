import sys
import keyboard
import pyautogui
from PySide2 import QtWidgets
from Form import Ui_Form

if __name__ == '__main__':
    app = QtWidgets.QApplication(sys.argv)

    form = QtWidgets.QMainWindow()
    Ui_Form = Ui_Form()
    Ui_Form.setupUi(form)
    form.show()

    pyautogui.PAUSE = 0.01

    def click_pos():
        if True:  ######## событие клика мышки по экрану ########
            click = 0
            while not keyboard.is_pressed('Esc'):
                position = pyautogui.position()
                Ui_Form.pos_X.setText(str(position.x))
                Ui_Form.pos_Y.setText(str(position.y))
                pyautogui.click()
                click += 1
                Ui_Form.click_sum.setText(str(click))
                print("число кликов: ", click, " в позиции: ", position.x, position.y)


    # ПРОБЛЕМА !!! Клик срабатывает несколько раз и столько же запускат функцию
    # >>> решение из меню РАТОРИ не подходит, там проверяется "and" движение мышки
    Ui_Form.GET_CLICK.clicked.connect(click_pos)

    # Вывод названий нажатых клавиш
    def print_pressed_keys(e):
        print(e, e.event_type, e.name)
        Ui_Form.key_name.setText(str(e.name))
    keyboard.hook(print_pressed_keys)

    sys.exit(app.exec_())
