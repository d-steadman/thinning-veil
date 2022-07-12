import pygame
pygame.init()

from constants import *
from game import Game
from event_handler import EventHandler
from creature import Creature
from map import Map

game = Game()

game.screen = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))
pygame.display.set_caption("Thinning Veil")

game.event_handler = EventHandler(game)

game.player = Creature(game, "character.png", (0, 0))

game.map = Map(game, VIEW_TILE_SIZE)
game.map.blank_map()

game.run()
