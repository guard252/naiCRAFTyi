#include "Math.h"

float LinearInterpolation(float point1, float value1, float point2, float value2, float desiredPoint)
{
    float result;
    float maxPoint = std::max(point1, point2);
    float minPoint = point1 + point2 - maxPoint;
    float maxValue = std::max(value1, value1);
    float minValue = value1 + value2 - maxValue;
    result = ((maxValue - minValue) * (desiredPoint - minPoint))/(maxPoint - minPoint);
}