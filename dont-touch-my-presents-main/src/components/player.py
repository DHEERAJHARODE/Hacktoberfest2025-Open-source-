import pygame
from pygame.locals import *

from src.config import Config
from src.services.visualization_service import VisualizationService

vec = pygame.math.Vector2


class Player(pygame.sprite.Sprite):
    def __init__(self):
        super().__init__()
        self.image = VisualizationService.get_player_image()
        self.rect = self.image.get_rect()
        self.mask = pygame.mask.from_surface(self.image)
        self.pos = vec((180, 550))
        self.vel = vec(0, 0)
        self.acc = vec(0, 0)
        self.player_position = vec(0, 0)

    def update(self):
        self.acc = vec(0, 0)

        pressed_keys = pygame.key.get_pressed()

        if pressed_keys[K_LEFT] or pressed_keys[K_a]:
            self.acc.x = -Config.ACC
        if pressed_keys[K_RIGHT] or pressed_keys[K_d]:
            self.acc.x = +Config.ACC
        if pressed_keys[K_UP] or pressed_keys[K_w]:
            self.acc.y = -Config.ACC
        if pressed_keys[K_DOWN] or pressed_keys[K_s]:
            self.acc.y = +Config.ACC

        self.acc.x += self.vel.x * Config.FRIC
        self.acc.y += self.vel.y * Config.FRIC
        self.vel += self.acc
        self.pos += self.vel + 0.5 * self.acc

        self.player_position = self.pos.copy()

        if self.pos.x > Config.WIDTH:
            self.pos.x = Config.WIDTH
        if self.pos.x < 0:
            self.pos.x = 0
        if self.pos.y > Config.HEIGHT:
            self.pos.y = Config.HEIGHT
        if self.pos.y < 200:
            self.pos.y = 200

        self.rect.center = self.pos

    def draw(self, screen):
        screen.blit(VisualizationService.get_santa_hand(), (self.rect.x - 25, self.rect.y - 25))
        screen.blit(self.image, self.rect)

    def reset(self):
        self.pos = vec((180, 550))
        self.vel = vec(0, 0)
        self.acc = vec(0, 0)
