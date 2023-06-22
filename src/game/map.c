#include "map.h"

uint8_t GetMapData(uint8_t mapData[MAP_WIDTH * MAP_HEIGHT], uint8_t x, uint8_t y)
{
	if (x > MAP_WIDTH || y > MAP_HEIGHT)
		return;

	return mapData[x + y * MAP_WIDTH];
}

uint8_t GetMapData(uint8_t mapData[MAP_WIDTH * MAP_HEIGHT], Point p)
{
	if (p.x > MAP_WIDTH || p.y > MAP_HEIGHT)
		return;

	return mapData[p.x + p.y * MAP_WIDTH];
}