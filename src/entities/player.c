#include "player.h"

void Move(Worm *p, Vector2 dir)
{
	for (uint8_t i = WORM_LEN - 1; i > 0; i--)
	{
		p->Body[i] = p->Body[i - 1]; // shift all body by one
	}

	p->Body[0].x += dir.x;
	p->Body[0].y += dir.y;
}

void DrawPlayer(Worm w)
{
	for (uint8_t i = 0; i < WORM_LEN; i++)
	{
		move_sprite(i * 2, w.Body[i].x * 16 + 8, w.Body[i].y * 16 + 16);
		move_sprite(i * 2 + 1, w.Body[i].x * 16 + 16, w.Body[i].y * 16 + 16);
	}
}