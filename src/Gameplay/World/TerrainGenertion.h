#ifndef NAICRAFTYI_TERRAINGENERTION_H
#define NAICRAFTYI_TERRAINGENERTION_H

#include <vector>
#include "ChunkTypedefs.h"
#include "../../Others/Math.h">
#include "glm/gtc/noise.hpp"

namespace Craft
{

    // Generates the world using simplex noise
    std::vector<std::vector<int>> GenerateWorldHeightMap(int width, int length, float frequency, int amplitude);

    std::vector<std::vector<int>> AddHeightMaps(std::vector<std::vector<int>> f, std::vector<std::vector<int>> s);

    std::vector<std::vector<int>> MapToWorldHeight(std::vector<std::vector<float>> heightMap, int lowBound, int hiBound);

};


#endif //NAICRAFTYI_TERRAINGENERTION_H
