#ifndef ENTITY_H
#define ENTITY_H

/*
Written by: Wil Steadman (07/23)

Entity and player structs and functionality.
Also includes an entity list for holding level entities.
*/

typedef struct {
    int x;
    int y;
} Position;

typedef struct Entity {
    Position pos;
    char symbol;

    // For entity list
    struct Entity *previous;
    struct Entity *next;
} Entity;

typedef enum {
    MOVE_DIR_UP,
    MOVE_DIR_DOWN,
    MOVE_DIR_RIGHT,
    MOVE_DIR_LEFT
} MoveDirection;

typedef enum {
    MOVE_STATUS_SUCCESS,    // Entity moved normally
    MOVE_STATUS_FAILED,     // Could not perform move
    MOVE_STATUS_NOT_REC     // Confirm move (used for player moves)
} MoveStatus;

/* Generic entity methods */
Entity *create_entity(Position start, char symbol);
void free_entity(Entity *entity);

// No map parameter, use extern
MoveStatus move_entity(Entity *entity, MoveDirection direction);

/* Player methods */
// No player parameter, use extern
void handle_input(int input);

/*
Entity list methods

Link entities together with player as head.
Include methods for filtering entities.
*/

// Don't need init function since we already have enemy creation

void entity_list_insert(Entity *new_entity);


// Extern variables
extern Entity *player;
extern Entity *entity_list;

#endif
