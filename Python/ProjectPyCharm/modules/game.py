import pygame

pygame.init()
g = pygame.display.set_mode((800, 600))
pygame.display.set_icon(pygame.image.load("images\icon.ico"))
pygame.display.set_caption("Ratori")

cat = pygame.image.load("images\cat.gif").convert_alpha()

game_music = pygame.mixer.music.load("sounds\music.mp3")
pygame.mixer.music.set_volume(0.5)

game_sound = pygame.mixer.Sound("sounds\zombi.mp3")

def game_cycle():
    game_state = True
    x = 20

    pygame.mixer.music.play(-1)

    pygame.mixer.Sound.play(game_sound)

    while game_state:

        for e in pygame.event.get():
            if e.type == pygame.QUIT:
                pygame.quit()
                quit()

        x += 1
        g.fill((15, 0, 64))
        pygame.draw.rect(g, (127, 255, 15), (x, x, 100, 75))

        g.blit(cat, (250, 350))

        pygame.time.Clock().tick(60)
        pygame.display.update()