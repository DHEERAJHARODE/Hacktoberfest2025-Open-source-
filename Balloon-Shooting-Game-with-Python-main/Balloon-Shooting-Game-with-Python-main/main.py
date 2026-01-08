''' Transfer required libraries '''
import pygame
import sys
import random
from math import *

''' Create A Desktop Window '''
pygame.init()
width = 700
height = 600
display = pygame.display.set_mode((width, height))
pygame.display.set_caption("Balloon Shooter Game")
clock = pygame.time.Clock()

''' Create variable for drawing and score '''
margin = 100
lowerBound = 100
score = 0

''' Generate random colors '''
white = (230, 230, 230)
lightBlue = (4, 27, 96)
red = (231, 76, 60)
lightGreen = (25, 111, 61)
darkGray = (40, 55, 71)
darkBlue = (64, 178, 239)
green = (35, 155, 86)
yellow = (244, 208, 63)
blue = (46, 134, 193)
purple = (155, 89, 182)
orange = (243, 156, 18)


''' Set the general font of the project '''
font = pygame.font.SysFont("Snap ITC", 35)


''' Create a class to do all balloon related operations '''
class Balloon:
    ''' Specify properties of balloons in start function '''
    def __init__(self, speed):
        self.a = random.randint(30, 40)
        self.b = self.a + random.randint(0, 10)
        self.x = random.randrange(margin, width - self.a - margin)
        self.y = height - lowerBound
        self.angle = 90
        self.speed = -speed
        self.proPool= [-1, -1, -1, 0, 0, 0, 0, 1, 1, 1]
        self.length = random.randint(50, 100)
        self.color = random.choice([red, green, purple, orange, yellow, blue])
        
    ''' Animate balloons using mathematical operators '''
    def move(self):
        direct = random.choice(self.proPool)

        if direct == -1:
            self.angle += -10
        elif direct == 0:
            self.angle += 0
        else:
            self.angle += 10

        self.y += self.speed*sin(radians(self.angle))
        self.x += self.speed*cos(radians(self.angle))

        if (self.x + self.a > width) or (self.x < 0):
            if self.y > height/5:
                self.x -= self.speed*cos(radians(self.angle)) 
            else:
                self.reset()
        if self.y + self.b < 0 or self.y > height + 30:
            self.reset()
            
    ''' Show balloons on screen '''
    def show(self):
        pygame.draw.line(display, darkBlue, (self.x + self.a/2, self.y + self.b), (self.x + self.a/2, self.y + self.b + self.length))
        pygame.draw.ellipse(display, self.color, (self.x, self.y, self.a, self.b))
        pygame.draw.ellipse(display, self.color, (self.x + self.a/2 - 5, self.y + self.b - 3, 10, 10))
            
    ''' Destroy by mouse click on the balloon '''
    def burst(self):
        global score
        pos = pygame.mouse.get_pos()

        if isonBalloon(self.x, self.y, self.a, self.b, pos):
            score += 1
            self.reset()
    ''' The process of resetting the balloons '''            
    def reset(self):
        self.a = random.randint(30, 40)
        self.b = self.a + random.randint(0, 10)
        self.x = random.randrange(margin, width - self.a - margin)
        self.y = height - lowerBound 
        self.angle = 90
        self.speed -= 0.002
        self.proPool = [-1, -1, -1, 0, 0, 0, 0, 1, 1, 1]
        self.length = random.randint(50, 100)
        self.color = random.choice([red, green, purple, orange, yellow, blue])

''' Create a list of balloons and set the number '''    
balloons = []
noBalloon = 10


''' Insert balloons into list using for loop '''
for i in range(noBalloon):
    obj = Balloon(random.choice([1, 1, 2, 2, 2, 2, 3, 3, 3, 4]))
    balloons.append(obj)

''' Check the balloons '''
def isonBalloon(x, y, a, b, pos):
    if (x < pos[0] < x + a) and (y < pos[1] < y + b):
        return True
    else:
        return False
    
''' Control cursor to pop balloon '''
def pointer():
    pos = pygame.mouse.get_pos()
    r = 25
    l = 20
    color = red
    for i in range(noBalloon):
        if isonBalloon(balloons[i].x, balloons[i].y, balloons[i].a, balloons[i].b, pos):
            color = red
    pygame.draw.ellipse(display, color, (pos[0] - r/2, pos[1] - r/2, r, r), 4)
    pygame.draw.line(display, color, (pos[0], pos[1] - l/2), (pos[0], pos[1] - l), 4)
    pygame.draw.line(display, color, (pos[0] + l/2, pos[1]), (pos[0] + l, pos[1]), 4)
    pygame.draw.line(display, color, (pos[0], pos[1] + l/2), (pos[0], pos[1] + l), 4)
    pygame.draw.line(display, color, (pos[0] - l/2, pos[1]), (pos[0] - l, pos[1]), 4)

''' Create subplatform '''
def lowerPlatform():
    pygame.draw.rect(display, darkGray, (0, height - lowerBound, width, lowerBound))
    
''' Show score on screen '''
def showScore():
    scoreText = font.render("Balloons Bursted : " + str(score), True, white)
    display.blit(scoreText, (150, height - lowerBound + 50))
    
''' Create function to close the game '''
def close():
    pygame.quit()
    sys.exit()
    

''' Create main function '''
def game():
    global score
    loop = True

    while loop:

        for event in pygame.event.get():
            ''' End the game only when the 'quit' button is pressed '''
            if event.type == pygame.QUIT:
                close()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_q:
                    close()
                if event.key == pygame.K_r:
                    score = 0
                    game()

            if event.type == pygame.MOUSEBUTTONDOWN:
                for i in range(noBalloon):
                    balloons[i].burst()

        display.fill(white)
        
        for i in range(noBalloon):
            balloons[i].show()

        pointer()
        
        for i in range(noBalloon):
            balloons[i].move()

        
        lowerPlatform()
        showScore()
        pygame.display.update()
        clock.tick(60)
        
game()