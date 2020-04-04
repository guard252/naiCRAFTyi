#ifndef NAICRAFTYI_RANDOM_H
#define NAICRAFTYI_RANDOM_H
#include <random>

struct Random
{
    static int GetInt();
    static int GetInt(int max);
    static int GetInt(int leftBound, int rightBound);

    static float GetFloat();
    static float GetFloat(float max);
    static float GetFloat(float leftBound, float rightBound);

    static double GetDouble();
    static double GetDouble(double max);
    static double GetDouble(double leftBound, double rightBound);

    static std::default_random_engine engine;
};


#endif //NAICRAFTYI_RANDOM_H
