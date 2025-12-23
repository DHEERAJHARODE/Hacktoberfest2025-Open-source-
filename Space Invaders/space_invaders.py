# Import required libraries
import pygame
from pygame import mixer
import random
import math

# Initialize the game
pygame.init()

# Create the game window (width, height)
screen = pygame.display.set_mode((800, 600))

# Load the background image
background = pygame.image.load('C:\\Users\\MY BOOK\\Desktop\\My Files\\p4ye\\New folder\\back.jpg')

# Background music
mixer.music.load('C:\\Users\\MY BOOK\\Desktop\\My Files\\p4ye\\New folder\\background.wav')
mixer.music.play(-1)  # -1 means the music will loop indefinitely

# Title and icon
pygame.display.set_caption("SPACE INVADERS")
icon = pygame.image.load('C:\\Users\\MY BOOK\\Desktop\\My Files\\p4ye\\New folder\\alien.png')
pygame.display.set_icon(icon)

# Player settings
playerImg = pygame.image.load('C:\\Users\\MY BOOK\\Desktop\\My Files\\p4ye\\New folder\\space-invaders.png')
playerX = 370
playerY = 480
playerX_change = 0

# Enemy settings
enemyImg = []
enemyX = []
enemyY = []
enemyX_change = []
enemyY_change = []
no_of_enemies = 6

# Initialize enemy properties for multiple enemies
for i in range(no_of_enemies):
    enemyImg.append(pygame.image.load('C:\\Users\\MY BOOK\\Desktop\\My Files\\p4ye\\New folder\\death.png'))
    enemyX.append(random.randint(0, 735))
    enemyY.append(random.randint(50, 150))
    enemyX_change.append(1.0)
    enemyY_change.append(40)

# Bullet settings
bulletImg = pygame.image.load('C:\\Users\\MY BOOK\\Desktop\\My Files\\p4ye\\New folder\\bullet.png')
bulletX = 0
bulletY = 480
bulletX_change = 0
bulletY_change = 3
bullet_state = "ready"

# Score
score_value = 0
font = pygame.font.Font('C:\\Users\\MY BOOK\\Desktop\\My Files\\p4ye\\New folder\\Yellow Rabbit - Personal Use.otf', 64)
textX = 10
textY = 10

# Game over text settings
over_font = pygame.font.Font('C:\\Users\\MY BOOK\\Desktop\\My Files\\p4ye\\New folder\\Yellow Rabbit - Personal Use.otf', 256)

# Function to display the player's score
def show_score(x, y):
    score = font.render("Score: " + str(score_value), True, (255, 255, 255))
    screen.blit(score, (x, y))

# Function to display "GAME OVER" when the game ends
def game_over_text():
    over_text = over_font.render("GAME OVER", True, (255, 255, 255))
    screen.blit(over_text, (280, 250))

# Function to display the player on the screen
def player(x, y):
    screen.blit(playerImg, (x, y))

# Function to display an enemy on the screen
def enemy(x, y, i):
    screen.blit(enemyImg[i], (x, y))

# Function to fire a bullet
def fire_bullet(x, y):
    global bullet_state
    bullet_state = "fire"
    screen.blit(bulletImg, (x + 16, y + 10))

# Function to check collision between the bullet and enemy
def isCollision(enemyX, enemyY, bulletX, bulletY):
    distance = math.sqrt(math.pow(enemyX - bulletX, 2) + math.pow(enemyY - bulletY, 2))
    if distance < 27:
        return True
    else:
        return False

# Main game loop
running = True
while running:
    # Fill the screen with a black background
    screen.fill((0, 0, 0))

    # Display the background image
    screen.blit(background, (0, 0))

    # Event handling
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                playerX_change = -3.0
            if event.key == pygame.K_RIGHT:
                playerX_change = 3.0
            if event.key == pygame.K_SPACE or event.key == pygame.K_UP:
                if bullet_state == "ready":
                    bullet_Sound = mixer.Sound('C:\\Users\\MY BOOK\\Desktop\\My Files\\p4ye\\New folder\\laser.wav')
                    bullet_Sound.play()
                    bulletX = playerX
                    fire_bullet(bulletX, bulletY)

        if event.type == pygame.KEYUP:
            if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:
                playerX_change = 0

    # Move the player within the screen boundaries
    playerX += playerX_change
    if playerX <= 0:
        playerX = 736
    elif playerX >= 736:
        playerX = 0

    # Enemy movement
    for i in range(no_of_enemies):
        if enemyY[i] > 440:
            for j in range(no_of_enemies):
                enemyY[j] = 2000
            game_over_text()
            break
        enemyX[i] += enemyX_change[i]

        if enemyX[i] <= 0:
            enemyX_change[i] = 1.0
            enemyY[i] += enemyY_change[i]
        elif enemyX[i] >= 736:
            enemyX_change[i] = -1.0
            enemyY[i] += enemyY_change[i]

        # Check for collision between bullet and enemy
        collision = isCollision(enemyX[i], enemyY[i], bulletX, bulletY)
        if collision:
            explosion_Sound = mixer.Sound('C:\\Users\\MY BOOK\\Desktop\\My Files\\p4ye\\New folder\\explosion.wav')
            explosion_Sound.play()
            bulletY = 480
            bullet_state = 'ready'
            score_value += 1
            enemyX[i] = random.randint(0, 735)
            enemyY[i] = random.randint(50, 150)

        enemy(enemyX[i], enemyY[i], i)

    # Bullet movement
    if bulletY <= 0:
        bulletY = 480
        bullet_state = "ready"
    if bullet_state == "fire":
        fire_bullet(bulletX, bulletY)
        bulletY -= bulletY_change

    # Display the player and score
    player(playerX, playerY)
    show_score(textX, textY)

    # Update the screen
    pygame.display.update()

# Quit the game
pygame.quit()
