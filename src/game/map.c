#include "map.h"

uint8_t GetMapData(uint8_t mapData[MAP_CHUNK_WIDTH * MAP_CHUNK_HEIGHT], uint8_t x, uint8_t y)
{
	if (x > MAP_CHUNK_WIDTH || y > MAP_CHUNK_HEIGHT)
		return;

	return mapData[x + y * MAP_CHUNK_WIDTH];
}

void SetMapCoordData(MapChunk *chunk, Point coord, uint8_t data)
{
	chunk->mapData[coord.x + coord.y * MAP_CHUNK_WIDTH] = data;
}