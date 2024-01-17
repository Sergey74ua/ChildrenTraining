import telebot
from telebot import types

import requests
import json

bot = telebot.TeleBot('6921844320:AAGCwcb378bNPiEGzB_PrCiG0bfonXz5TPU')

user = {}
params = {}

headers = {"Token": "POMOGITE33333333333333"}


@bot.message_handler(commands=['start'])
def start(message):
    user_id = message.from_user.id
    user['id'] = user_id

    bot.send_message(message.from_user.id, 'Здравствуйте, введите номер своей группы')


@bot.message_handler(content_types=['text'])
def name(message):
    user['group'] = message.text
    params['Group'] = message.text

    bot.send_message(message.from_user.id, 'Теперь введите имя!')
    bot.register_next_step_handler(message, last_name)


@bot.message_handler(content_types=['text'])
def last_name(message):
    user['name'] = message.text

    bot.send_message(message.from_user.id, 'Теперь введите фамилию!')
    bot.register_next_step_handler(message, show)


@bot.message_handler(content_types=['text'])
def show(message):
    user['last_name'] = message.text
    bot.send_message(message.from_user.id, str(user))

    if 'group' in user and 'name' in user and 'last_name' in user:
        markup = types.ReplyKeyboardMarkup(resize_keyboard=True)

        oddweek = types.KeyboardButton('Нечёт')
        evenweek = types.KeyboardButton('Чёт')
        markup.add(oddweek, evenweek)

        bot.send_message(message.from_user.id, 'Выберите чётность недели', reply_markup=markup)
        bot.register_next_step_handler(message, weeks)


def weeks(message):
    if message.text == 'Нечёт':
        params['Week'] = 'oddweek'

        markup = types.ReplyKeyboardMarkup(resize_keyboard=True)

        monday = types.KeyboardButton('Понедельник')
        tuesday = types.KeyboardButton('Вторник')
        wednesday = types.KeyboardButton('Среда')
        thursday = types.KeyboardButton('Четверг')
        friday = types.KeyboardButton('Пятница')
        back = types.KeyboardButton('Назад')
        markup.add(monday, tuesday, wednesday, thursday, friday, back)

        bot.send_message(message.from_user.id, 'Выбирайте!', reply_markup=markup)
        bot.register_next_step_handler(message, this_days)

    if message.text == 'Чёт':
        params['Week'] = 'evenweek'

        markup = types.ReplyKeyboardMarkup(resize_keyboard=True)

        monday = types.KeyboardButton('Понедельник')
        tuesday = types.KeyboardButton('Вторник')
        wednesday = types.KeyboardButton('Среда')
        thursday = types.KeyboardButton('Четверг')
        friday = types.KeyboardButton('Пятница')
        back = types.KeyboardButton('Назад')
        markup.add(monday, tuesday, wednesday, thursday, friday, back)

        bot.send_message(message.from_user.id, 'Выбирайте!', reply_markup=markup)
        bot.register_next_step_handler(message, this_days)


def this_days(message):
    if message.text == 'Понедельник':
        params['Day'] = 'Monday'

    if message.text == 'Вторник':
        params['Day'] = 'Tuesday'

    if message.text == 'Среда':
        params['Day'] = 'Wednesday'

    if message.text == 'Четверг':
        params['Day'] = 'Thursday'

    if message.text == 'Пятница':
        params['Day'] = 'Friday'

    markup = types.ReplyKeyboardMarkup(resize_keyboard=True)

    timetable = types.KeyboardButton('Расписание на...')
    where_is = types.KeyboardButton('Где...')
    comment = types.KeyboardButton('Оставить комментарий...')
    markup.add(timetable, comment, where_is)

    bot.send_message(message.from_user.id, 'Выберите, что вам нужно', reply_markup=markup)
    bot.register_next_step_handler(message, on_click)


def on_click(message):
    if message.text == 'Расписание на...':
        url = f"http://localhost:8080/api/getSchedule?group={params['Group']}&week={params['Week']}&day={params['Day']}"
        resp = requests.post(url, headers=headers)
        answer = json.loads(resp.text)

        formatted_answer = ""
        for lesson in answer["Lessons"]:
            formatted_answer += f"Пара №{lesson['Number']}:\n"
            formatted_answer += f"Тип: {lesson['Type']}\n"
            formatted_answer += f"Название: {lesson['Name']}\n"
            formatted_answer += f"Учитель: {lesson['Teacher']}\n"
            formatted_answer += f"Комната: {lesson['Room']}\n"
            formatted_answer += f"Комментарий: {lesson['Comment']}\n\n"

        markup = types.ReplyKeyboardMarkup(resize_keyboard=True)

        thanks = types.KeyboardButton('Спасибо')
        markup.add(thanks)

        bot.send_message(message.from_user.id, formatted_answer, reply_markup=markup)
        bot.register_next_step_handler(message, again)

    if message.text == 'Оставить комментарий...':
        bot.send_message(message.from_user.id, 'Введите номер пары, к которой вы хотите оставить комментарий')
        bot.register_next_step_handler(message, comm)

    if message.text == 'Где...':
        markup = types.ReplyKeyboardMarkup(resize_keyboard=True)

        group = types.KeyboardButton('...группа')
        prepod = types.KeyboardButton('...преподаватель')
        markup.add(group, prepod)
        bot.send_message(message.from_user.id, '...', reply_markup=markup)
        bot.register_next_step_handler(message, number)


def comm(message):
    params['Number'] = message.text
    bot.send_message(message.from_user.id, 'Напишите свой комментарий...')
    bot.register_next_step_handler(message, cont)


def cont(message):
    params['Comment'] = message.text

    url = f"http://localhost:8080/api/updateComment?group={params['Group']}&week={params['Week']}&day={params['Day']}&number={params['Number']}&comment={params['Comment']}"
    resp = requests.post(url, headers=headers)

    bot.send_message(message.from_user.id, 'Ваш комментарий добавлен!')


def number(message):
    if message.text == '...группа':
        bot.send_message(message.from_user.id, 'Введите нужный номер пары')
        bot.register_next_step_handler(message, groups)

    if message.text == '...преподаватель':
        bot.send_message(message.from_user.id, 'Введите номер пары, которую ведёт интересующий вас преподаватель')
        bot.register_next_step_handler(message, teachers)


def groups(message):
    params['Number'] = message.text

    url = f"http://localhost:8080/api/getGroupRoom?group={params['Group']}&week={params['Week']}&day={params['Day']}&number={params['Number']}"
    resp = requests.post(url, headers=headers)
    answer = resp.content.decode('utf-8')

    markup = types.ReplyKeyboardMarkup(resize_keyboard=True)

    thanks = types.KeyboardButton('Спасибо')
    markup.add(thanks)

    bot.send_message(message.from_user.id, 'Группа в аудитории ' + answer, reply_markup=markup)
    bot.register_next_step_handler(message, again)


def teachers(message):
    params['Number'] = message.text

    bot.send_message(message.from_user.id, 'Введите полное ФИО преподавателя')
    bot.register_next_step_handler(message, teacher)


def teacher(message):
    params['Teacher'] = message.text

    url = f"http://localhost:8080/api/getTeacherRoom?group={params['Group']}&week={params['Week']}&day={params['Day']}&number={params['Number']}&teacher={params['Teacher']}"
    resp = requests.post(url, headers=headers)
    answer = resp.content.decode('utf-8')

    markup = types.ReplyKeyboardMarkup(resize_keyboard=True)

    thanks = types.KeyboardButton('Спасибо')
    markup.add(thanks)

    bot.send_message(message.from_user.id, 'Преподаватель в аудитории ' + answer, reply_markup=markup)
    bot.register_next_step_handler(message, again)


def again(message):
    if message.text == 'Спасибо':
        params.clear()
        user.clear()
        bot.register_next_step_handler(message, start)


bot.polling(none_stop=True)