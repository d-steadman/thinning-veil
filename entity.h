#ifndef ENTITY_H
#define ENTITY_H

/*
Written by: Wil Steadman (07/23)

Entity and player structs and functionality.
Also includes an entity list for holding level entities.
*/

#include <ncurses.h>
#include <stdlib.h>

/*
Entity location to eliminate providing X and Y.
*/
typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position pos;
    Direction last_move;

    char symbol;
} Entity;

enum MoveDirection {
    MOVE_DIR_FORWARD,   // Moves the same direction as the previous move
    MOVE_DIR_UP,
    MOVE_DIR_DOWN,
    MOVE_DIR_RIGHT,
    MOVE_DIR_LEFT
}

enum MoveStatus {
    MOVE_STATUS_SUCCESS,    // Entity moved normally
    MOVE_STATUS_FAILED,     // Could not perform move
    MOVE_STATUS_NOT_REC     // Confirm move (used for player moves)
}

// Generic entity methods
Entity *create_entity(Position start, char symbol);
MoveStatus move_entity(Entity *entity, MoveDirection direction);

// Player methods
void handle_input(int input);

// Extern variables
extern Entity *player;

#endif
