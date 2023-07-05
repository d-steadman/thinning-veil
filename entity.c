#include <ncurses.h>
#include <stdlib.h>

#include "entity.h"

Entity *create_entity(Position start, char symbol) {
    Entity *new_entity = calloc(1, sizeof(Entity));

    new_entity->pos.x = start.x;
    new_entity->pos.y = start.y;
    new_entity->symbol = symbol;

    new_entity->previous = NULL;
    new_entity->next = NULL;

    return new_entity;
}

void free_entity(Entity *entity) {
    free(entity);
}

void entity_list_insert(Entity *new_entity) {
    // Move to last entity in list
    Entity *current = entity_list;

    while (current->next)
        next = next->next;

    new_entity->previous = current;
    current->next = new_entity;
}

void entity_list_delete(Entity *entity) {
    Entity *previous = entity->previous;
    Entity *next = entity->next;

    previous->next = next;
    next->previous = previous;

    free_entity(entity);
}
