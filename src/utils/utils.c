#include "utils.h"
#include <gb/gb.h>

int8_t LUT_SIN(uint8_t v)
{
    const int8_t sinlut[256] = {0, 2, 5, 7, 10, 12, 15, 17, 20, 22, 24, 27, 29, 31, 34, 36, 38, 41, 43, 45, 47, 49, 52, 54, 56, 58, 60, 62, 64, 66, 67, 69, 71, 73, 74, 76, 78, 79, 81, 82, 83, 85, 86, 87, 88, 90, 91, 92, 93, 93, 94, 95, 96, 97, 97, 98, 98, 99, 99, 99, 100, 100, 100, 100, 100, 100, 100, 100, 99, 99, 99, 98, 98, 97, 97, 96, 95, 95, 94, 93, 92, 91, 90, 89, 88, 87, 85, 84, 83, 81, 80, 78, 77, 75, 73, 72, 70, 68, 66, 65, 63, 61, 59, 57, 55, 53, 51, 48, 46, 44, 42, 40, 37, 35, 33, 30, 28, 26, 23, 21, 18, 16, 14, 11, 9, 6, 4, 1, -1, -4, -6, -9, -11, -14, -16, -18, -21, -23, -26, -28, -30, -33, -35, -37, -40, -42, -44, -46, -48, -51, -53, -55, -57, -59, -61, -63, -65, -66, -68, -70, -72, -73, -75, -77, -78, -80, -81, -83, -84, -85, -87, -88, -89, -90, -91, -92, -93, -94, -95, -95, -96, -97, -97, -98, -98, -99, -99, -99, -100, -100, -100, -100, -100, -100, -100, -100, -99, -99, -99, -98, -98, -97, -97, -96, -95, -94, -93, -93, -92, -91, -90, -88, -87, -86, -85, -83, -82, -81, -79, -78, -76, -74, -73, -71, -69, -67, -66, -64, -62, -60, -58, -56, -54, -52, -49, -47, -45, -43, -41, -38, -36, -34, -31, -29, -27, -24, -22, -20, -17, -15, -12, -10, -7, -5, -2};
    return sinlut[v];
}

bool PointBoxCollision(Point p, Box b)
{
    if (p.x > b.x + b.w)
        return false;
    else if (p.x < b.x)
        return false;
    if (p.y > b.y + b.h)
        return false;
    else if (p.y < b.y)
        return false;
    return true;
}