#include <gb/gb.h>

#ifndef FILE_UTILS
#define FILE_UTILS

#define true 1
#define false 0

typedef int8_t bool;

typedef struct Point_t
{
    uint8_t x;
    uint8_t y;
} Point;

typedef struct Box_t
{
    uint8_t x;
    uint8_t y;
    uint8_t w;
    uint8_t h;
} Box;

bool PointBoxCollision(Point p, Box b);

int8_t LUT_SIN(uint8_t v); // REDO

#endif