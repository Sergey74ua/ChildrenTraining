#Автокликер https://github.com/boppreh/mouse

import mause
from time import sleep

while True:
    if mause.is_pressed(button = 'LEFT'):
        while True:
            sleep(0.0001)
            mause.double_click(button = 'LEFT')

def is_pressed(button=LEFT):
    """ Returns True if the given button is currently pressed. """
    _listener.start_if_necessary()
    return button in _pressed_events

def click(button=LEFT):
    """ Sends a click with the given button. """
    _os_mouse.press(button)
    _os_mouse.release(button)

def double_click(button=LEFT):
    """ Sends a double click with the given button. """
    click(button)
    click(button)