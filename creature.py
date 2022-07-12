import pygame

from constants import *

class Creature:
    def __init__(self, game, image_filepath, tile_position):
        self._game = game
        self._image = pygame.image.load(image_filepath)
        self.x, self.y = tile_position

    def blit(self):
        self._game.screen.blit(self._image,
                               (VIEW_ORIGIN[0] + self.x * TILE_WIDTH,
                                VIEW_ORIGIN[1] + self.y * TILE_HEIGHT))

    def move(self, dx, dy):
        self.x += dx
        self.y += dy
