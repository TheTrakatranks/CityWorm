#include <gb/gb.h>
#include <stdio.h>

#include "utils/types.h"

enum GAME_STATES
{
	TITLE_SCREEN,
	CREDITS,
	GAME,
	END_SCREEN
};

void main()
{
	SPRITES_8x16;

	SHOW_SPRITES;
	SHOW_BKG;
}