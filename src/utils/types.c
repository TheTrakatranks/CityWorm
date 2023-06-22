#include "types.h"

Vector2 VectorAdd(Vector2 a, Vector2 b)
{
	Vector2 v = {a.x + b.x, a.y + b.y};
	return v;
}

Vector2 VectorMul(Vector2 a, int8_t b)
{
	Vector2 v = {a.x * b, a.y * b};
	return v;
}

Vector2 VectorNormalize(Vector2 a)
{
	Vector2 v = {a.x, a.y};
	return v;
}