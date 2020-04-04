#include "TerrainGenertion.h"
#include "ChunkConstants.h"


namespace Craft
{
    /*
     * This function generates heightMaps for
     * the part of a terrain
     */
    std::vector<std::vector<int>> GenerateWorldHeightMap(int width, int length, float frequency, int amplitude)
    {
        std::vector<std::vector<int>> heightMap(width);
        for (int i = 0; i < width; i++)
        {
            heightMap[i] = std::vector<int>(length);
        }
        for (int x = 0; x < width; x++)
        {
            for (int y = 0; y < length; y++)
            {
                float value = glm::simplex(glm::vec2{x / frequency, y / frequency});
                heightMap[x][y] = std::abs(MapTo(0, amplitude, 0, 1, value));
            }
        }
        return heightMap;

    }

    std::vector<std::vector<int>> AddHeightMaps(std::vector<std::vector<int>> f, std::vector<std::vector<int>> s)
    {
        std::vector<std::vector<int>> result = f;
        for(int i = 0; i < result.size(); i++)
        {
            for(int j = 0; j < result.size(); j++)
            {
                result[i][j] += s[i][j];
            }
        }
        return result;
    }

    std::vector<std::vector<int>> MapToWorldHeight(std::vector<std::vector<float>> heightMap, int lowBound, int hiBound)
    {
       /* int width = heightMap.size();
        int length = heightMap[0].size();
        std::vector<std::vector<int>> result(width);

        for (int x = 0; x < width; x++)
        {
            for (int y = 0; y < length; y++)
            {
                float value = glm::simplex(glm::vec2{x / strength, y / strength});
                result[x][y] = std::abs(MapTo(57, 73, 0, 1, value));
            }
        }*/

    }

}