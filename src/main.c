#include <gb/gb.h>
#include <stdio.h>

#include "main.h"

void setGameState(GAME_STATE state)
{
	GameState = state;

	switch (state) // on state active action
	{
	case TITLE_SCREEN:
		HIDE_BKG;
		HIDE_SPRITES;
		break;

	case GAME:
		gfx_init();
		SHOW_BKG;
		SHOW_SPRITES;
		player = *initPlayer();
		Point spawnPos;
		spawnPos.x = 3;
		spawnPos.y = 5;
		SpawnWorm(&player, spawnPos);
		break;

	case END_SCREEN:
		break;

	default:
		break;
	}
}

void titleScreenUpdate()
{
	printf("press start");
	waitpad(J_START);
	setGameState(GAME);
}

void pauseUpdate()
{
}

void gameUpdate()
{
	lastPadState = padState;
	padState = joypad();

	if (padState & ~lastPadState)
	{
		MoveWorm(&player, padState, lastPadState);
		set_bkg_tiles(0, 0, M_CityMapWidth, M_CityMapHeight, M_CityMap);
		DrawWorm(player);
	}
}

void endScreenUpdate()
{
}

void gfx_init()
{
	set_bkg_data(0, T_CityLen, T_City);
	set_bkg_data(T_CityLen, worm_tLen, worm_t);
}

void main()
{
	SPRITES_8x16;
	// NR52_REG = 0x80;
	// NR50_REG = 0x77;
	// NR51_REG = 0xff;

	while (1)
	{
		switch (GameState)
		{
		case TITLE_SCREEN:
			titleScreenUpdate();
			break;

		case GAME:
			gameUpdate();
			break;

		case END_SCREEN:
			endScreenUpdate();
			break;

		default:
			break;
		}
	}
}