#include "../utils/types.h"
#include <gb/gb.h>

#ifndef FILE_MAP
#define FILE_MAP

#define MAP_CHUNK_WIDTH 10
#define MAP_CHUNK_HEIGHT 9

#define WORLD_WIDTH 5
#define WORLD_HEIGHT 5

enum TILE_IDS
{
	EMPTY,
	WATER,
	HOUSE,
	FOOD,
	PLAYER
};

typedef struct MapChunk_t
{
	uint8_t mapData[MAP_CHUNK_WIDTH * MAP_CHUNK_HEIGHT];
} MapChunk;

typedef struct WorldMap_t
{
	uint8_t chunkTable[WORLD_WIDTH * WORLD_HEIGHT];
} WorldMap;

uint8_t GetMapData(uint8_t mapData[MAP_CHUNK_WIDTH * MAP_CHUNK_HEIGHT], uint8_t x, uint8_t y);
void SetMapCoordData(MapChunk *chunk, Point coord, uint8_t data);
#endif