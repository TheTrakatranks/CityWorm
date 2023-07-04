#include "../utils/types.h"

#ifndef FILE_PLAYER
#define FILE_PLAYER

#define WORM_LEN 7

typedef struct Worm
{
	uint8_t hp;
	Point Body[WORM_LEN];
} Worm;

void Move(Worm *p, Vector2 dir);
void DrawPlayer(Worm w);

#endif