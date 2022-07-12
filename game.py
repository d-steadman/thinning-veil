# A game container for holding and managing game objects

import pygame

class Game:
    def __init__(self):
        self.is_running = True

        # Game objects
        self.screen = None
        self.event_handler = None
        self.player = None
        self.creatures = [self.player]
        self.items = []
        self.map = None

    def run(self):
        """
        Handles the game's mainloop
        """
        while self.is_running:
            # Handle user input(s)
            event_queue = pygame.event.get()
            self.event_handler.handle_event_queue(event_queue)

            # Handle graphical updates
            self.screen.fill((255, 255, 230))

            self.map.blit()

            self.player.blit()

            pygame.display.update()

        pygame.quit()
