#include <locale.h>
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>



// Terminal default externs
int terminal_width, terminal_height;

// Game externs
Entity *entity_list = NULL;
Entity *player = NULL;

/*
Encapsulated ncurses terminal setup
*/
void ncurses_setup(){
    setlocale(LC_ALL, "");  // Allows use of Unicode charset

    initscr();

    // Get terminal window width & height
    getmaxyx(stdscr, terminal_height, terminal_width);
}

int main(){
	ncurses_setup();

    const cchar_t wall = {A_BLINK, L"\u2592"};
    const cchar_t floor = {A_NORMAL, L" "};


	for (int x = 0; x < terminal_width; x++){
		for (int y = 0; y < terminal_height; y++){
			noise = open_simplex_noise2(ctx, x*SCALE, y*SCALE);
			mvadd_wch(y, x, noise > CUTOFF ? &wall : &floor);
		}
	}

	getch();

	endwin();

	open_simplex_noise_free(ctx);

	return 0;
}
