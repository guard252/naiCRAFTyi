#include "TerrainGenertion.h"
#include "ChunkConstants.h"


namespace Craft
{
    /*
     * This function generates heightMaps for
     * the part of a terrain
     */
    std::vector<std::vector<int>> GenerateWorldHeightMap(int width, int length)
    {
        std::vector<std::vector<int>> heightMap(width);
        for (int i = 0; i < width; i++)
        {
            heightMap[i] = std::vector<int>(length);
        }
        int octave_step = OCTAVE_PRIMARY_STEP;
        for (int x = 0; x < width; x++)
        {
            for (int y = 0; y < length; y++)
            {
                float value = glm::simplex(glm::vec2{x / 64.0, y / 64.0});
                heightMap[x][y] = std::abs(MapTo(0, 15, 0, 1, value));
            }
        }
        return heightMap;

    }
}