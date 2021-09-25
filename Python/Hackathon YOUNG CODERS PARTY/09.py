name, number, summ, sex = input().split(',')
if sex == 'Ж':
    sex = 'ая '
else:
    sex = 'ый '
print('Уважаем' + sex + name + ' на вашем счете (карта VISA' + number[-4:] + ') осталось ' + summ + ' руб.')


#Дорешивание