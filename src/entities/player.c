#include "player.h"
#include "../gfx/cityMap.h"

Worm *initPlayer()
{
	Worm w;

	w.hp = 5;
	for (uint8_t i = 0; i < WORM_LEN; i++)
	{
		w.Body[i].visual.hidden = true;
	}
	return &w;
}

void SpawnWorm(Worm *w, Point pos)
{
	w->Body[0].pos = pos;
	w->Body[0].visual.hidden = false;
}

void MoveWorm(Worm *p, uint8_t padState, uint8_t lastPadState)
{
	for (uint8_t i = WORM_LEN - 1; i > 0; i--) // first is tail
	{
		p->Body[i] = p->Body[i - 1]; // shift all body by one
	}

	p->Body[1].visual.hidden = false;

	if (padState & J_UP)
	{
		p->Body[0].pos.y -= 1;
		p->Body[0].visual.from = J_DOWN;
		p->Body[1].visual.to = J_UP;
	}
	else if (padState & J_DOWN)
	{
		p->Body[0].pos.y += 1;
		p->Body[0].visual.from = J_UP;
		p->Body[1].visual.to = J_DOWN;
	}

	if (padState & J_LEFT)
	{
		p->Body[0].pos.x -= 1;
		p->Body[0].visual.from = J_RIGHT;
		p->Body[1].visual.to = J_LEFT;
	}
	else if (padState & J_RIGHT)
	{
		p->Body[0].pos.x += 1;
		p->Body[0].visual.from = J_LEFT;
		p->Body[1].visual.to = J_RIGHT;
	}

	SetHeadVisual(&(p->Body[0]), p->Body[0].visual.from);
	for (uint8_t i = 1; i < WORM_LEN - 1; i++) // first is tail
	{
		SetMidVisual(&(p->Body[i]), p->Body[i].visual.from, p->Body[i].visual.to);
	}
	SetTailVisual(&(p->Body[WORM_LEN - 1]), p->Body[WORM_LEN - 1].visual.to);
}

void DrawWorm(Worm w) // The WHOLE snake is drawn in bkg
{
	for (uint8_t i = 0; i < WORM_LEN; i++)
	{
		if (w.Body[i].visual.hidden)
			continue;

		uint8_t px = w.Body[i].pos.x * 2;
		uint8_t py = w.Body[i].pos.y * 2;

		set_bkg_tile_xy(px, py, w.Body[i].visual.topleft);
		set_bkg_tile_xy(px + 1, py, w.Body[i].visual.topright);
		set_bkg_tile_xy(px, py + 1, w.Body[i].visual.bottomleft);
		set_bkg_tile_xy(px + 1, py + 1, w.Body[i].visual.bottomright);
	}
}

void SetHeadVisual(WormNode *wn, uint8_t from)
{
	switch (from)
	{
	case J_UP: // Head goes down
		wn->visual.topleft = 0x38;
		wn->visual.topright = 0x39;
		wn->visual.bottomleft = 0x43;
		wn->visual.bottomright = 0x45;
		break;
	case J_DOWN: // Head goes up
		wn->visual.topleft = 0x42;
		wn->visual.topright = 0x44;
		wn->visual.bottomleft = 0x38;
		wn->visual.bottomright = 0x39;
		break;
	case J_LEFT: // Head goes right
		wn->visual.topleft = 0x36;
		wn->visual.topright = 0x46;
		wn->visual.bottomleft = 0x37;
		wn->visual.bottomright = 0x47;

		break;
	case J_RIGHT: // Head goes left
		wn->visual.topleft = 0x48;
		wn->visual.topright = 0x36;
		wn->visual.bottomleft = 0x49;
		wn->visual.bottomright = 0x37;

		break;

	default: // head from hole
		break;
	}
}

void SetMidVisual(WormNode *wn, uint8_t from, uint8_t to)
{
	switch (from | to)
	{
	case J_UP | J_DOWN:
		wn->visual.topleft = 0x38;
		wn->visual.topright = 0x39;
		wn->visual.bottomleft = 0x38;
		wn->visual.bottomright = 0x39;
		break;
	case J_UP | J_LEFT:
		wn->visual.topleft = 0x3A;
		wn->visual.topright = 0x39;
		wn->visual.bottomleft = 0x37;
		wn->visual.bottomright = 0x41;
		break;
	case J_UP | J_RIGHT:
		wn->visual.topleft = 0x38;
		wn->visual.topright = 0x3C;
		wn->visual.bottomleft = 0x3F;
		wn->visual.bottomright = 0x37;
		break;
	case J_DOWN | J_LEFT:
		wn->visual.topleft = 0x36;
		wn->visual.topright = 0x40;
		wn->visual.bottomleft = 0x3B;
		wn->visual.bottomright = 0x39;
		break;
	case J_DOWN | J_RIGHT:
		wn->visual.topleft = 0x3E;
		wn->visual.topright = 0x36;
		wn->visual.bottomleft = 0x38;
		wn->visual.bottomright = 0x3D;
		break;
	case J_LEFT | J_RIGHT:
		wn->visual.topleft = 0x36;
		wn->visual.topright = 0x36;
		wn->visual.bottomleft = 0x37;
		wn->visual.bottomright = 0x37;
		break;

	case J_UP:
		wn->visual.topleft = 0x36;
		wn->visual.topright = 0x36;
		wn->visual.bottomleft = 0x37;
		wn->visual.bottomright = 0x37;
		break;
	case J_DOWN:
		wn->visual.topleft = 0x36;
		wn->visual.topright = 0x36;
		wn->visual.bottomleft = 0x37;
		wn->visual.bottomright = 0x37;
		break;
	case J_LEFT:
		wn->visual.topleft = 0x36;
		wn->visual.topright = 0x36;
		wn->visual.bottomleft = 0x37;
		wn->visual.bottomright = 0x37;
		break;
	case J_RIGHT:
		wn->visual.topleft = 0x36;
		wn->visual.topright = 0x36;
		wn->visual.bottomleft = 0x37;
		wn->visual.bottomright = 0x37;
		break;

	default: // error
		wn->visual.hidden = true;
		break;
	}
}

void SetTailVisual(WormNode *wn, uint8_t to)
{
	switch (to)
	{
	case J_UP:
		wn->visual.topleft = 0x38;
		wn->visual.topright = 0x39;
		wn->visual.bottomleft = 0x51;
		wn->visual.bottomright = 0x53;
		break;
	case J_DOWN:
		wn->visual.topleft = 0x50;
		wn->visual.topright = 0x52;
		wn->visual.bottomleft = 0x38;
		wn->visual.bottomright = 0x39;
		break;
	case J_LEFT:
		wn->visual.topleft = 0x36;
		wn->visual.topright = 0x55;
		wn->visual.bottomleft = 0x37;
		wn->visual.bottomright = 0x54;
		break;
	case J_RIGHT:
		wn->visual.topleft = 0x57;
		wn->visual.topright = 0x36;
		wn->visual.bottomleft = 0x56;
		wn->visual.bottomright = 0x37;
		break;

	default:
		break;
	}
}