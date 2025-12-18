import pygame

from src.components.game_status import GameStatus
from src.config import Config


class GlobalState:
    GAME_STATE = GameStatus.MAIN_MENU
    SCREEN = None
    SCROLL = 0
    PRESS_Y = 650

    @staticmethod
    def load_main_screen():
        screen = pygame.display.set_mode((Config.WIDTH, Config.HEIGHT))
        screen.fill((0, 255, 255))
        GlobalState.SCREEN = screen
