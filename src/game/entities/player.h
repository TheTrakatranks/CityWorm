#include "../../utils/types.h"

#ifndef FILE_PLAYER
#define FILE_PLAYER

typedef struct Player
{
    Point pos;
    uint8_t hp;
} Player;

void Move(Player *p);

#endif