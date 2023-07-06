#include <gb/gb.h>

#ifndef FILE_TYPES
#define FILE_TYPES

#define true 1
#define false 0
typedef uint8_t bool;

typedef struct Point_t
{
	uint8_t x, y;
} Point, Vector2;

typedef struct Box_t
{
	uint8_t x, y;
	uint8_t width, height;
} Box;

Vector2 VectorAdd(Vector2 a, Vector2 b);
Vector2 VectorMul(Vector2 a, int8_t b);
Vector2 VectorNormalize(Vector2 a);

#endif