#include "Random.h"

int Random::GetInt()
{
    std::uniform_int_distribution<int> distribution;
    //std::default_random_engine engine;
    return distribution(engine);
}

int Random::GetInt(int max)
{
    std::uniform_int_distribution<int> distribution(0, abs(max));
    //std::default_random_engine engine;
    return distribution(engine);
}

int Random::GetInt(int leftBound, int rightBound)
{
    std::uniform_int_distribution<int> distribution(leftBound, rightBound);
   // std::default_random_engine engine;
    return distribution(engine);
}

float Random::GetFloat()
{
    std::uniform_real_distribution<float> distribution;
   // std::default_random_engine engine;
    return distribution(engine);
}

float Random::GetFloat(float max)
{
    std::uniform_real_distribution<float> distribution(0, fabs(max));
   // std::default_random_engine engine;
    return distribution(engine);
}

float Random::GetFloat(float leftBound, float rightBound)
{
    std::uniform_real_distribution<float> distribution(leftBound, rightBound);
    return distribution(engine);
}

double Random::GetDouble()
{
    std::uniform_real_distribution<double> distribution;
    //std::default_random_engine engine;
    return distribution(engine);
}

double Random::GetDouble(double max)
{
    std::uniform_real_distribution<double> distribution(0, fabs(max));
   // std::default_random_engine engine;
    return distribution(engine);
}

double Random::GetDouble(double leftBound, double rightBound)
{
    std::uniform_real_distribution<double> distribution(leftBound, rightBound);
  //  std::default_random_engine engine;
    return distribution(engine);
}
