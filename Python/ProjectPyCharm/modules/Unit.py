import pygame

pygame.init()

class Unit(object):
    # тестовый юнит

    def __init__(self):
        self.img = pygame.image.load("images\tank.png").convert_alpha()
    pass