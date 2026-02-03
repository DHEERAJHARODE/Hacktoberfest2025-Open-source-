import pygame
import os
pygame.font.init()
pygame.mixer.init()

WIDTH, HEIGHT = 900, 500
WIN = pygame.display.set_mode((WIDTH,HEIGHT))
pygame.display.set_caption("Zfight")
BLUE=(0,0,255)
BLACK=(0,0,0)
YELLOW=(255,255,0)
PURPLE=(255,0,255)
GREEN=(0,255,0)
FPS = 60
SPRITE_DIM = 55
VEL = 5
BLAST_VEL=8
BORDER=pygame.Rect(WIDTH//2 -5, 0, 10, HEIGHT)
MAX_BLAST = 3

GOKU_HIT = pygame.USEREVENT +1
VEGETA_HIT = pygame.USEREVENT +2

GOKU = pygame.image.load(os.path.join('assets','goku.png'))
GOKU = pygame.transform.scale(GOKU,(SPRITE_DIM,SPRITE_DIM))             #resizing the sprites
VEGETA = pygame.image.load(os.path.join('assets','vegeta.png'))
VEGETA = pygame.transform.scale(VEGETA,(SPRITE_DIM,SPRITE_DIM))
BG=pygame.transform.scale(pygame.image.load(os.path.join('assets','background.jpg')),(WIDTH,HEIGHT))
KI_SOUND= pygame.mixer.Sound('assets/kiblast.mp3')
KI_BLAST_GOKU= pygame.transform.scale(pygame.image.load(os.path.join('assets','kiblast.png')),(30,20))
KI_BLAST_VEGETA= pygame.transform.scale(pygame.image.load(os.path.join('assets','kiblastveg.png')),(30,20))

HEALTH_FONT = pygame.font.SysFont('comisans',40)
WINNER_FONT = pygame.font.SysFont('comicsans', 100)

def draw_win(gok, veg, gok_blast, veg_blast, GOKU_HEALTH, VEGETA_HEALTH):
    WIN.blit(BG,(0,0))
    pygame.draw.rect(WIN, BLACK, BORDER)

    goku_health_text= HEALTH_FONT.render("Health: " + str(GOKU_HEALTH), 1, GREEN)
    vegeta_health_text= HEALTH_FONT.render("Health: " + str(VEGETA_HEALTH), 1, GREEN)
    WIN.blit(goku_health_text,(10,10))
    WIN.blit(vegeta_health_text,(WIDTH - vegeta_health_text.get_width() - 10,10))

    WIN.blit(GOKU,(gok.x,gok.y))                #adding the sprites to the display, every object is called a surface in python
    WIN.blit(VEGETA,(veg.x,veg.y))

    for blast in gok_blast:
          WIN.blit(KI_BLAST_GOKU,(blast.x,blast.y))
    for blast in veg_blast:
          WIN.blit(KI_BLAST_VEGETA,(blast.x,blast.y))
          
    pygame.display.update()                 #we have to manually update the display when we change it

def move_goku(keys_pressed,gok):
    if(keys_pressed[pygame.K_a]) and gok.x - VEL >0:    #move goku left
            gok.x -= VEL
    if(keys_pressed[pygame.K_d]) and gok.x + VEL < WIDTH/2 -60:    #move goku right
            gok.x += VEL
    if(keys_pressed[pygame.K_w]) and gok.y -VEL >0:    #move goku up
            gok.y -= VEL
    if(keys_pressed[pygame.K_s]) and gok.y + VEL <500 -55:    #move goku down
            gok.y += VEL

def move_vegeta(keys_pressed,veg):
    if(keys_pressed[pygame.K_LEFT]) and veg.x - VEL > WIDTH/2 +5:    #move vegeta left
            veg.x -= VEL
    if(keys_pressed[pygame.K_RIGHT]) and veg.x + VEL < 900 -55:    #move vegeta right
            veg.x += VEL
    if(keys_pressed[pygame.K_UP]) and veg.y - VEL > 0:    #move vegeta up
            veg.y -= VEL
    if(keys_pressed[pygame.K_DOWN]) and veg.y - VEL < 500 -55:    #move vegeta down
            veg.y += VEL

def blast_handle(gok_blast, veg_blast, gok, veg):
      for blast in gok_blast:
            blast.x += BLAST_VEL
            if veg.colliderect(blast):
                  pygame.event.post(pygame.event.Event(VEGETA_HIT))
                  gok_blast.remove(blast) 
            elif blast.x>= WIDTH:
                  gok_blast.remove(blast)
                      
      for blast in veg_blast:
            blast.x -= BLAST_VEL
            if gok.colliderect(blast):
                  pygame.event.post(pygame.event.Event(GOKU_HIT))
                  veg_blast.remove(blast)
            elif blast.x<= 0:
                  veg_blast.remove(blast)

def draw_winner(WINNER):
      text=WINNER_FONT.render(WINNER, 1, BLUE)
      WIN.blit(text, (WIDTH //2 - text.get_width()//2, HEIGHT//2 - text.get_height()//2))
      pygame.display.update()
      pygame.time.delay(5000)

def main():
    gok = pygame.Rect(200, 250, SPRITE_DIM, SPRITE_DIM)
    veg = pygame.Rect(WIDTH-200, 250, SPRITE_DIM, SPRITE_DIM)

    gok_blast = []
    veg_blast = []

    GOKU_HEALTH =10
    VEGETA_HEALTH =10

    clock=pygame.time.Clock()
    run = True
    while run:
        clock.tick(FPS)                             #defining the speed of while loop so that it runs at same speed in all devices
        for event in pygame.event.get():            #checks for the events in pygame
            if event.type == pygame.QUIT:
                run=False

            if event.type == pygame.KEYDOWN:
                  if event.key == pygame.K_LCTRL and len(gok_blast) <=MAX_BLAST:
                        KI_SOUND.play()
                        blast = pygame.Rect(gok.x + gok.width, gok.y + gok.height//2 -2 ,10,5)
                        gok_blast.append(blast)
                  if event.key == pygame.K_RCTRL and len(veg_blast) <=MAX_BLAST :
                        KI_SOUND.play()
                        blast = pygame.Rect(veg.x, veg.y + veg.height//2 -2 ,10,5)
                        veg_blast.append(blast)

            
            WINNER = ""

            if GOKU_HEALTH <=0:
                  WINNER="VEGETA WINS!"
            
            if VEGETA_HEALTH <=0:
                  WINNER="GOKU WINS!"
            
            if WINNER != "":
                  draw_winner(WINNER)
                  main()

            if event.type == GOKU_HIT:
                  GOKU_HEALTH -=1

            if event.type == VEGETA_HIT:
                  VEGETA_HEALTH -=1

        keys_pressed = pygame.key.get_pressed()
        move_goku(keys_pressed,gok)
        move_vegeta(keys_pressed,veg)
        blast_handle(gok_blast,veg_blast,gok,veg)

        draw_win(gok,veg,gok_blast,veg_blast,GOKU_HEALTH,VEGETA_HEALTH)

    pygame.quit()

# this allows the file only to run directly run not when it was imported ,basically tells this is the main file
if __name__ == "__main__":
    main()