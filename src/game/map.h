#include "../utils/types.h"
#include <gb/gb.h>

#ifndef FILE_MAP
#define FILE_MAP

#define MAP_WIDTH 10
#define MAP_HEIGHT 9

enum TILE_IDS
{
	EMPTY,
	WATER,
	HOUSE,
	FOOD,
	SNAKE
};

uint8_t GetMapData(uint8_t mapData[MAP_WIDTH * MAP_HEIGHT], uint8_t x, uint8_t y);
uint8_t GetMapData(uint8_t mapData[MAP_WIDTH * MAP_HEIGHT], Point p);

#endif