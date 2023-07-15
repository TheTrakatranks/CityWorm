#include "utils/utils.h"

#include "gfx/city.h"
#include "gfx/cityMap.h"
#include "gfx/worm.h"

#include "utils/types.h"

#include "entities/player.h"

#ifndef FILE_MAIN
#define FILE_MAIN

typedef enum GAME_STATE_E
{
	TITLE_SCREEN = 0,
	GAME,
	END_SCREEN
} GAME_STATE;

GAME_STATE GameState;

void main();

void titleScreenUpdate();
void gameUpdate();
void endScreenUpdate();
void pauseUpdate();

void gfx_init();

void setGameState(GAME_STATE gameState);

uint8_t padState, lastPadState;

Worm player;

#endif