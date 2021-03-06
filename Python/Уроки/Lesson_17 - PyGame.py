
cat = pygame.image.load("images/cat.gif")
pygame.mixer.music.load("sounds/music.mp3")
pygame.mixer.music.set_volume(0.2)
x = 20

def draw(self, g):
    g.fill((31, 31, 63))

    pygame.mixer.music.play(-1)
    pygame.mixer.music.pause()

    pygame.draw.line(g, 'yellow', (20, 50), (700, 400), 2)
    pygame.draw.aaline(g, 'white', (30, 80), (750, 280))
    pygame.draw.aalines(g, 'white', True, [(30, 70), (750, 270), (600, 50), (800, 300)])

    pygame.draw.polygon(g, (240, 127, 15), ((200, 200), (250, 180), (230, 250), (200, 150), (350, 350)), 3)
    pygame.draw.polygon(g, 'orange', ((500, 500), (550, 480), (530, 550), (500, 450), (650, 650)), 0)

    pygame.draw.circle(g, 'red', (600, 200), 50)
    pygame.draw.circle(g, 'purple', (620, 280), 50, 2)

    pygame.draw.ellipse(g, 'blue', (410, 350, 280, 100), 1)
    pygame.draw.arc(g, 'black', (50, 400, 200, 150), 3.14, 6.28, 16)

    g.blit(self.cat, (250, 250))

    font = pygame.font.Font(None, 32)
    msg = 'Hello world!'
    text = font.render(msg, True, pygame.Color('gray'))
    g.blit(text, (350, 50))

    font = pygame.font.SysFont('serif', 48)
    msg = 'Привет мир'
    text = font.render(msg, True, pygame.Color('white'))
    g.blit(text, (350, 80))

    if self.x < 350:
        self.x += 1
    pygame.draw.rect(g, 'green', (self.x, self.x, 100, 75))

#########################################################

def TEST(self, pos):
    """ УЧЕБНАЯ функция проверки наложения курсора и кнопки """
    if ((pos[0] > self.rect.x) and (pos[0] < self.rect.x+self.rect.width)
            and (pos[1] > self.rect.y) and (pos[1] < self.rect.y+self.rect.height)):
        print(pos)
        print(self.rect)
        return True  # 1 или что угодно
    else:
        return False  # 0
    # или проще
    return ((pos[0] > self.rect.x) and (pos[0] < self.rect.x+self.rect.width)
            and (pos[1] > self.rect.y) and (pos[1] < self.rect.y+self.rect.height))

#########################################################

for e in pg.event.get():
    if e.type == pg.QUIT:
        quit()
    if e.type == pg.MOUSEBUTTONUP and e.button == 1:
        pg.mixer.music.unpause()
        #pygame.menu_state = not menu_state
    if menu_state:
    display.set_mode((800, 640), RESIZABLE)
    game_menu.draw_menu(g)
else:
    display.set_mode((0, 0), FULLSCREEN)
    obj_OOP.draw(g)

#########################################################

list_ground = sprite.Group()
for y in range(8):
    for x in range(8):
        frame = Ground(room_01[y][x], x, y)
        list_ground.add(frame)

list_unit = sprite.Group()
for i in range(5):
    unit = Unit((i*200, i*100))
    list_unit.add(unit)
