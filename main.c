#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "entity.h"
#include "open-simplex.h"

#define SCALE 0.2
#define CUTOFF 0

// Terminal default externs
int terminal_width, terminal_height;

// Game externs
Entity *entity_list = NULL;
Entity *player = NULL;

/*
Encapsulated ncurses terminal setup
*/
void ncurses_setup(){
    initscr();

    // Get terminal window width & height
    getmaxyx(stdscr, terminal_height, terminal_width);
}

int main(){
	// Open Simplex
	struct osn_context *ctx;
	double noise;

	if (open_simplex_noise(0LL, &ctx) != 0) {
		printf("Error: could not create Open Simplex context\n");
		exit(1);
	}

	ncurses_setup();

	for (int x = 0; x < terminal_width; x++){
		for (int y = 0; y < terminal_height; y++){
			noise = open_simplex_noise2(ctx, x*SCALE, y*SCALE);
			mvaddch(y, x, noise > CUTOFF ? '#' : '.');
		}
	}

	getch();

	endwin();

	open_simplex_noise_free(ctx);

	return 0;
}
