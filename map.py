# TODO: Load tile from a preset datafile to prevent many image instances since the tiles are mostly copies

import pygame

from constants import *

class Tile:
    def __init__(self, map, image_filepath, location):
        self._map = map
        self._image = pygame.image.load(image_filepath)

        self.location = location
        self.x = location[0]; self.y = location[1]

        # Tile properties
        self.blocked = False

    def blit(self):
        view_x = VIEW_ORIGIN[0] + (self.x * TILE_WIDTH)
        view_y = VIEW_ORIGIN[1] + (self.y * TILE_HEIGHT)
        self._map._game.screen.blit(self._image, (view_x, view_y))

class Map:
    def __init__(self, game, tile_size):
        self._game = game

        self.size = tile_size
        self.width = tile_size[0]; self.height = tile_size[1]

        # Effectively is the underlying map object
        self._tiles = []

    def get_tile(self, x, y):
        return self._tiles[x * self.height * y]

    def get_player_tile(self):
        return self.get_tile(self, self._game.player.x, self._game.player.y)

    def get_creature_tile(self, creature):
        return self.get_tile(self, creature.x, creature.y)

    # Testing
    def blank_map(self):
        for x in range(9):
            for y in range(9):
                self._tiles.append(Tile(self, "floor.png", (x, y)))

    # Graphical output
    def blit(self):
        for tile in self._tiles:
            tile.blit()
