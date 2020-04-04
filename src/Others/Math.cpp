#include "Math.h"

/*
 * This function maps the dot product (0.0-1.0)
 * to the chunk position (0 - CHUNK_SIZE - 1)
 */
int MapToBlockPosition(float val, int max)
{
    return fabs(val) * (max - 1);
}

float MapToZeroOne(int val, int max)
{
    return float(val) / float(max);
}

float MapTo(float destMin, float destMax, float srcMin, float srcMax, float toMap)
{
    return destMin + ((destMax - destMin) / (srcMax - srcMin)) * (toMap - srcMin);
}