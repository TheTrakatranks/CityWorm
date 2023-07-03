#include <gb/gb.h>
#include <stdio.h>

#include "gfx/city.h"
#include "gfx/cityMap.h"
#include "gfx/worm.h"
#include "utils/types.h"

#include "entities/player.h"

typedef enum GAME_STATE_E
{
	TITLE_SCREEN = 0,
	GAME,
	END_SCREEN
} GAME_STATE;

void SetState(GAME_STATE state)
{
	uint8_t s = state;
}

Worm w = {5};
uint8_t padState, lastPadState;

void TitleScreenUpdate()
{
}

void GameUpdate()
{
	// @todo Move player code to player file

	Vector2 dir = {0, 0};

	if ((padState & J_LEFT) & ~lastPadState)
	{
		dir.x = -1;
		Move(&w, dir);
	}
	else if ((padState & J_RIGHT) & ~lastPadState)
	{
		dir.x = 1;
		Move(&w, dir);
	}

	if ((padState & J_UP) & ~lastPadState)
	{
		dir.y = -1;
		Move(&w, dir);
	}
	else if ((padState & J_DOWN) & ~lastPadState)
	{
		dir.y = 1;
		Move(&w, dir);
	}

	DrawPlayer(w);
}

void EndScreenUpdate()
{
}

void main()
{
	SPRITES_8x16;

	set_bkg_data(0, T_CityLen, T_City);
	set_bkg_tiles(0, 0, M_CityMapWidth, M_CityMapHeight, M_CityMap);

	set_sprite_data(0, T_WormLen, T_Worm);
	// straight h
	set_sprite_tile(0, 0);
	set_sprite_tile(1, 2);
	// straight v
	set_sprite_tile(2, 4);
	set_sprite_tile(3, 6);
	// corner
	set_sprite_tile(4, 8);
	set_sprite_tile(5, 10);
	// head ud
	set_sprite_tile(6, 12);
	set_sprite_tile(7, 14);
	// head lr
	set_sprite_tile(8, 16);
	set_sprite_tile(9, 18);
	// head hole
	set_sprite_tile(10, 20);
	set_sprite_tile(11, 22);
	// corner hole
	set_sprite_tile(12, 24);
	set_sprite_tile(13, 26);
	// up hole
	set_sprite_tile(14, 28);
	set_sprite_tile(15, 30);
	// down hole
	set_sprite_tile(16, 32);
	set_sprite_tile(17, 34);

	SHOW_BKG;
	SHOW_SPRITES;

	Point pos = {3, 7};

	w.Body[0] = pos;
	w.Body[1] = pos;
	w.Body[2] = pos;
	w.Body[3] = pos;
	w.Body[4] = pos;

	GAME_STATE gameState = TITLE_SCREEN;

	while (1) // gameloop
	{
		lastPadState = padState;
		padState = joypad();

		switch (gameState)
		{
		case TITLE_SCREEN:
			waitpad(J_START);
			gameState = GAME;
			break;

		case GAME:
			GameUpdate();
			break;

		case END_SCREEN:
			break;

		default:
			break;
		}
	}
}