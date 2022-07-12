import pygame
# No init here, just using constants

from pygame.locals import (
    K_UP, K_DOWN, K_RIGHT, K_LEFT
)

from collections import defaultdict

class EventHandler:
    def __init__(self, game, log=False, verbose=False):
        self._game = game    # A global game object so events can affect other classes

        # Options
        self._record_event_log = log
        self._verbose = verbose

        self._event_log = []    # Optional log for recreating game states

        # Movement keys

        # Set local key constants so keys can be easily changed
        #TODO: Load keys from file

        self.UP = K_UP
        self.DOWN = K_DOWN
        self.RIGHT = K_RIGHT
        self.LEFT = K_LEFT
        self._movement_keys = (K_UP, K_DOWN, K_RIGHT, K_LEFT)

        self._movement_lookup = {
            self.UP: (0, -1),
            self.DOWN: (0, 1),
            self.RIGHT: (1, 0),
            self.LEFT: (-1, 0),
        }

        # Handler lookup for each event
        # NOTE: Default dict allows handling of all events even if they aren't expected
        self._hander_lookup = defaultdict(lambda: self._not_implemented)
        self._hander_lookup[pygame.QUIT] = self._quit
        self._hander_lookup[pygame.KEYDOWN] = self._keydown

    def handle(self, event):
        """
        Accepts an event as input and defers it to the appropriate handler method.
        This is mostly for manual and debug operation, because events are normally
        handled as a queue.
        """
        self._hander_lookup[event.type](event)

        if self._record_event_log:
            self._event_log.append(event)

    def handle_event_queue(self, queue):
        """
        Loops through the queue of events and handles them. Very simple code, but
        allows us to hide the loops.
        """
        for event in queue:
            self.handle(event)

    # Handler functions

    def _quit(self, event):
        self._game.is_running = False

    def _keydown(self, event):
        # For movement, use lookup for direct, then pass to player's move method
        if event.key in self._movement_keys:
            dx, dy = self._movement_lookup.get(event.key)
            self._game.player.move(dx, dy)

    def _not_implemented(self, event):
        if self._verbose:
            event_name = pygame.event.event_name(event.type)
            print(f"[WARNING] Event '{event_name}' not implemented")
