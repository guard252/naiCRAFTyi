#ifndef NAICRAFTYI_MATH_H
#define NAICRAFTYI_MATH_H
#include <algorithm>
#include <cmath>

inline float lerp(float s, float e, float t)
{
    return s+(e-s)*t;
}

inline float blerp(float c00, float c10, float c01, float c11, float tx, float ty)
{
    return lerp(lerp(c00, c10, tx), lerp(c01, c11, tx), ty);
}
int MapToBlockPosition(float val, int max);

float MapToZeroOne(int val, int max);

float MapTo(float destMin, float destMax, float srcMin, float srcMax, float toMap);

#endif //NAICRAFTYI_MATH_H
