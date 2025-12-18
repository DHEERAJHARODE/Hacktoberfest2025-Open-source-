import random

import pygame

from paths import AUDIO_DIR


class MusicService:
    @staticmethod
    def get_background_musics():
        return [
            AUDIO_DIR / "sleigh_ride.ogg",
            AUDIO_DIR / "merry_christmas.ogg",
            AUDIO_DIR / "here_comes_santa.ogg"
        ]

    @staticmethod
    def get_chop_musics():
        return [
            AUDIO_DIR / "chop.wav",
            AUDIO_DIR / "chop_2.wav",
            AUDIO_DIR / "chop_3.wav"
        ]

    @staticmethod
    def get_cheer_musics():
        return [
            AUDIO_DIR / "cheer.wav",
            AUDIO_DIR / "cheer_2.wav",
            AUDIO_DIR / "cheer_3.wav",
            AUDIO_DIR / "cheer_4.wav"
        ]

    @staticmethod
    def start_background_music():
        if pygame.mixer.music.get_busy():
            return

        musics = MusicService.get_background_musics()
        filename = random.choice(musics)
        pygame.mixer.music.load(filename)
        pygame.mixer.music.play()

    @staticmethod
    def play_chop_sound():
        musics = MusicService.get_chop_musics()
        filename = random.choice(musics)
        chop = pygame.mixer.Sound(filename)
        pygame.mixer.Sound.play(chop)

    @staticmethod
    def play_score_sound():
        score_sfx = pygame.mixer.Sound(AUDIO_DIR / "score.wav")
        pygame.mixer.Sound.play(score_sfx)

    @staticmethod
    def play_slap_sound():
        slap_sfx = pygame.mixer.Sound(AUDIO_DIR / "slap.wav")
        pygame.mixer.Sound.play(slap_sfx)

    @staticmethod
    def play_cheer_sound():
        musics = MusicService.get_cheer_musics()
        filename = random.choice(musics)
        cheer = pygame.mixer.Sound(filename)
        pygame.mixer.Sound.play(cheer)
