#include "../utils/types.h"

#ifndef FILE_PLAYER
#define FILE_PLAYER

typedef struct Worm
{
	uint8_t hp;
	Point Body[5];
} Worm;

void Move(Worm *p, Vector2 dir);
void DrawPlayer(Worm w);

#endif