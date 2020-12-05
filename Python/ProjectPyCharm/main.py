# Установка библиотек:
# pip install pygame
# pip install pyside2

# В gitignore добавляем папку venv
# Сохраняем список библиотек:
# pip freeze > requirements.txt
# Установка библиотек по списку:
# pip install -r requirements.txt

from modules import game

if __name__ == '__main__':
    game.game_cycle()