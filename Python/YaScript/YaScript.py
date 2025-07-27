'''
Скрипт для "Перенос текста рекламного объявления с картинки"
Sergey - 12.07.2025
НАДО:
1 Заменить распознаватель
2 Внедрить блокировку отправки
3 Определять раскладку клавиатуры
4 Устанавливать положение окна консоли
5 pyperclip - либо убрать, либо использовать
6 Заменить выделение области пером на pyautogui
7 Сигналы при окончании работы и сбоях
8 Улучшить планирование работы часы/задания, примерно 1:100
'''

from PIL import ImageGrab
from random import randint
import pytesseract
import pyautogui
import pyperclip
import time


# Координаты точек в окне браузера
inTitle=''				# Огиринал заголовка
inDescript=''			# Ориганал описания
outTitle=''				# Очищеный заголовок
outDescript=''			# Очищеное описание

lenScroll=-200			# Длинна сколла
pntActiv=[60,500]		# Точка активации браузера
pntImage=[200,475]		# Точка просмотра картинки
pntLightShot=[848,68]	# Кнопка скриншотера
pntEnter=[895,995]		# Кнопка отправки задания

startTitle=[190,518]	# Начало заголовка
endTitle=[800,555]		# Конец заголовка
startDescript=[190,568]	# Начало описания
endDescript=[800,605]	# Конец описания

sendTitle=[150,795]		# Поле очищенного заголовка
sendDescript=[150,900]	# Поле очищенного описания

taskCount=0				# Счетчик заданий
pyautogui.PAUSE = 0.7
pyautogui.FAILSAFE = True


# Проверка позиционирования окон, языка и открытого задания
# (255, 238, 169),(255, 213, 46),(255, 210, 32),(255, 215, 54),(255, 212, 40)
# (255, 212,  40),(255, 219, 75),(255, 218, 69), (255, 220, 80)
def testBrowser():
	col=pyautogui.pixel(pntEnter[0],pntEnter[1])
	if col!=(255,221,83) and col!=(255,210,31) and col!=(255, 238, 169) and col!=(255, 213, 46) and col!=(255, 215, 54):
		timeCurrent=time.strftime("%H:%M:%S",time.localtime())
		print(taskCount, timeCurrent, col, 'Проблемы с заданием ...')
		stop=input()

# Скриншот в буфер
def screenBuffer(start,end):
	# Выделение и копирование текста
	# А ТАК? screenshot=ImageGrab.grab(bbox=(x, y, x+500, y+20))
	pyautogui.moveTo(pntLightShot[0],pntLightShot[1])
	pyautogui.click()
	time.sleep(2)
	pyautogui.moveTo(start[0],start[1])
	pyautogui.dragTo(end[0],end[1],duration=1)
	pyautogui.hotkey('ctrl', 'c')
	time.sleep(2)
	# Получаем картинку из буфера и текст из нее
	try:
		image=ImageGrab.grabclipboard()
		if image:
			text = pytesseract.image_to_string(image, lang='rus+eng')
			return text
		else:
			print("Не удалось распознать текст из изображении или в буфер обмена пустой.")
			return None
	except ImportError as e:
		print(f"Ошибка импорта: {e}. Проверьте библиотеки (Pillow, pytesseract).")
		return None
	except Exception as e:
		print(f"Произошла ошибка: {e}")
		return None
	return outText

# Очистка текста
def clearText(inText):
	# При отсутствии вводного текста
	if not inText:
		return 'нет текста'
	outText=''
	for i in range(len(inText)):
		# Русские, латинские буквы и цифры
		if inText[i].isalpha() or inText[i].isdigit():
			outText+=inText[i]
		# Заменяем на пробел, если его уже нет
		elif i>0:
			if outText[-1:]!=' ':
				outText+=' '
		# Заменяем X между числами на русский
		if i>1 and outText[-1:].isdigit():
			if outText[-3:-2].isdigit():
				if outText[-2:-1]=='x':
					outText=outText[:-2]+'х'+outText[-1]
				elif outText[-2:-1]=='X':
					outText=outText[:-2]+'Х'+outText[-1]
	# Проверка пробелов по краям
	outText=outText.strip()
	# При отсутствии очищенного текста
	if len(outText)==0:
		outText='нет текста'
	print(inText.strip())
	print(outText)
	return outText

# Вставляем данные и сдаем задание
def sendTask(outTitle,outDescript):
	# Вставляем заголовок
	pyautogui.moveTo(sendTitle[0],sendTitle[1])
	pyautogui.click()
	pyautogui.click()
	pyperclip.copy(outTitle)
	pyautogui.hotkey('ctrl', 'v')
	# Вставляем описание
	pyautogui.moveTo(sendDescript[0],sendDescript[1])
	pyautogui.click()
	pyperclip.copy(outDescript)
	pyautogui.hotkey('ctrl', 'v')


''' СТАРТ ПРОГРАММЫ '''

# Определяем время работы
while True:
	timeStart=time.time()
	hour=input('Браузер! Консоль! ENG!  Введите часы: ')
	if hour=='':
		timeWork=14400-randint(0,600)
		break
	elif not hour.isdigit() or (int(hour)<=0 or int(hour)>24):
		print('Введите число от 0 до 24')
		continue
	else:
		timeWork=int(hour)*3600-randint(0,600)
		break

# Главный рабочий цикл
while time.time()-timeStart<timeWork:
	# Проверка доступности задания
	taskCount+=1
	timeCurrent=time.strftime("%H:%M:%S",time.localtime())
	print(str(taskCount).ljust(3, ' '),timeCurrent)
	time.sleep(2)
	testBrowser()
	# Активация браузера, скролл
	pyautogui.moveTo(pntActiv[0],pntActiv[1])
	pyautogui.click()
	pyautogui.scroll(lenScroll)
	# Раскрываем картинку с текстом
	pyautogui.moveTo(pntImage[0],pntImage[1])
	pyautogui.click()
    # Получаем заголовок
	inTitle=screenBuffer(startTitle,endTitle)
	outTitle=clearText(inTitle)
	# Получаем описание
	inDescript=screenBuffer(startDescript,endDescript)
	outDescript=clearText(inDescript)
	# Вставляем данные и сдаем задание
	sendTask(outTitle,outDescript)
	# Выдерживаем время и сдаем задание
	time.sleep(4)
	pyautogui.moveTo(pntEnter[0],pntEnter[1])
	pyautogui.click()
