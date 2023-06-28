#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "open-simplex.h"

#define SCALE 0.2
#define CUTOFF 0

int main(){
	int terminal_width = -1, terminal_height = -1;

	// Open Simplex
	struct osn_context *ctx;
	double noise;

	if (open_simplex_noise(0LL, &ctx) != 0) {
		printf("Error: could not create Open Simplex context\n");
		exit(1);
	}

	initscr();

	getmaxyx(stdscr, terminal_height, terminal_width);


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
