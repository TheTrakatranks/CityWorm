#include "../utils/types.h"

#ifndef FILE_PLAYER
#define FILE_PLAYER

#define WORM_LEN 7 // AT LEAST 4 LONG

typedef struct NodeVisual_T
{
	uint8_t from;
	uint8_t to;
	uint8_t topleft;
	uint8_t topright;
	uint8_t bottomleft;
	uint8_t bottomright;
	bool hidden;
} NodeVisual;

// STRUCTS
typedef struct WormNode_T
{
	Vector2 pos;
	NodeVisual visual;
} WormNode;

typedef struct Worm_T
{
	uint8_t hp;
	WormNode Body[WORM_LEN];
} Worm;

// FUNCTIONS
Worm *initPlayer();
void SpawnWorm(Worm *w, Point pos);
void MoveWorm(Worm *p, uint8_t padState, uint8_t lastPadState);
void DrawWorm(Worm w);
void SetHeadVisual(WormNode *wn, uint8_t from);
void SetMidVisual(WormNode *wn, uint8_t from, uint8_t to);
void SetTailVisual(WormNode *wn, uint8_t to);

#endif