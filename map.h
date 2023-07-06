#ifndef MAP_H
#define MAP_H

/*
Written by: Wil Steadman (07/23)

Map generation algorithms using OpenSimplex noise.
*/

/* Represents one square of the map */
typedef struct {
    /* Tile properties */
    Surface surface;

    /* Things inhabiting the tile */
    Entity *entity_sky;
    Entity *entity_ground;
    Entity *entity_underground;

    //Item *item_list;  // Linked list for items
} Tile;

typedef struct Map {
    int64_t seed;
    int width;
    int height;

    Tile *tiles;
}

typedef enum {
    DIRT,
    WALL,
    GRASS
} Surface;

/* Map struct creation functions */
Tile *init_tile(Surface surface);
Map *init_map(int64_t seed, int width, int height);

#endif
