#ifndef NAICRAFTYI_TERRAINGENERTION_H
#define NAICRAFTYI_TERRAINGENERTION_H

#include <vector>
#include "ChunkTypedefs.h"
#include "../../Others/Math.h">
#include "glm/gtc/noise.hpp"

namespace Craft
{

    // Generates the world using perlin noise
    std::vector<std::vector<int>> GenerateWorldHeightMap(int width, int length);


};


#endif //NAICRAFTYI_TERRAINGENERTION_H
