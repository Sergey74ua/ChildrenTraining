import pyautogui as a

class ClassTEMP():
    a.PAUSE = 0.5  # задержка между командами

    def __init__(self):
        self.win = a.size()  # Размер экрана
        self.pos = a.position()  # Позиция курсора
        self.col = a.pixel(self.pos.x, self.pos.y)  # Цвет пикселя экрана

    def start_bot1(self):
        print(self.win, type(self.win))
        print(self.pos, type(self.pos))
        print(self.col, type(self.col), self.col[0])

        a.alert(text='Hello world!', title='Окно № 1')
        text = 'Hello world!'
        a.confirm(text, title='Окно № 2', buttons=['OK', 'Cancel'])
        a.prompt(text, title='Окно № 3', default='введите текст')
        a.password(text, title='Окно № 4', default='', mask='*')

    def start_bot2(self):
        a.move(100, -200)  # перемещение мыши относительно ее предыдущего расположения
        a.moveTo(self.win.width//2, self.win.height//2)  # перемещение мыши на X, Y
        a.move(400, 300, duration=3.5)  # относительное перемещение мыши в течении 3.5 секунд
        a.moveTo(500, 200, duration=1.2)  # перемещение мыши на X, Y, в течение 1.2 секунд

    """
    a.moveRel(20, -50, duration=0.4)
    a.dragTo(1000, 400, duration=2.0)
    a.dragRel(-100, -20, duration=1.0)
    a.click(1150, 690, clicks=1, interval=0.8, button='left')
    
    a.dragTo(100, 200, button='left')  # перемещение мыши на X 100, Y 200 с удержанием левой кнопки
    a.dragTo(300, 400, 2, button='left')  # перемещение мыши на X 300, Y 400 в течение 2 секунд с удержанием левой кнопки
    a.click()  # щелчок мыши
    a.click(x=100, y=200)  # перемещение на 100, 200, а затем нажатие левой кнопкой
    a.click(button='right')  # щелчок правой кнопкой мыши
    a.doubleClick()  # двойной щелчок левой кнопкой
    a.click(clicks=2)  # двойной щелчок левой кнопкой мыши
    a.click(clicks=2, interval=0.25)  # двойной щелчок левой кнопкой мыши с паузой в четверть секунды между щелчками
    a.scroll(10)  # прокрутка на 10 "кликов" вверх
    a.scroll(-10)  # прокрутка на 10 "кликов" вниз
    a.hscroll(10)  # прокрутка на 10 "кликов" вправо
    a.hscroll(-10)  # прокрутка на 10 "кликов" влево
    a.click('button.png')  # Найдите на экране место, где появляется button.png, и щелкните его.
    
    a.keyDown("enter")  # нажали
    a.keyUp("enter")  # отпустили
    a.press("enter")  # нажали и отпутили
    
    # Чтобы нажать несколько клавиш, аргументы передаются в виде списка
    a.press(['enter', 'tab', 'enter'])
    
    a.hotkey('ctrl', 'alt', 'delete')
    # Эквивалентно следующему коду:
    a.keyDown('ctrl')
    a.keyDown('alt')
    a.keyDown('delete')
    a.keyUp('delete')
    a.keyUp('alt')
    a.keyUp('ctrl')

    a.write('Hello world!', interval=0.25)
    a.typewrite("Hello world!")
    a.typewrite('Hello world!', interval=0.25)

    scr = a.screenshot()
    scr.save('screen.png')
    a.screenshot (region = (0,0, 300, 400))
    
    # Поиск изображение на экране
    a.locateOnScreen('key5.png') # Выдаст начальные x, y
    a.locateCenterOnScreen() # Выдаст x, y центра рисунка
    
    # Проверка цвета точки True/False , tolerance - отклонение цвета
    a.pixelMatchesColor(100, 200, (140, 125, 134))
    a.pixelMatchesColor(100, 200, (140, 125, 134), tolerance=10)
    """
