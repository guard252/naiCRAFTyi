#ifndef NAICRAFTYI_TERRAIN_H
#define NAICRAFTYI_TERRAIN_H
#include "Chunk.h"
#include <map>
#include <array>
#include <unordered_map>
#include <cmath>
#include "../../Others/Random.h"
#include "../../Others/Math.h"
#include "TerrainGenertion.h"

namespace Craft
{
    class Terrain
    {
        const GL::ShaderProgram& shader;
        ChunkTable chunks;
        //std::unordered_map<std::pair<int, int>, glm::vec2, KeyFunctions> randVectors;
        //std::unordered_map<ChunkPosition, HeightMap, KeyFunctions, KeyFunctions> heightMaps;
        std::vector<std::vector<int>> heightMap;
    private:
        const int TERRAIN_PRIMARY_WIDTH = 10;
        const int TERRAIN_PRIMARY_LENGTH = 10;
        const int TERRAIN_DEPTH = 1;
    private:
        void GenerateSmoothWorld();
       // void GenerateRandomVectors();
       // HeightMap GenerateColumnHeightMap(const glm::vec2& column);
    public:
        Terrain(const GL::ShaderProgram& _shader);
        ~Terrain();
        void GeneratePlaneWorld();
        BlockType GetBlock(BlockWorldPosition position);
        BlockType GetBlock(ChunkPosition ch, BlockChunkPosition bl);
        void SetBlockUnsafe(BlockWorldPosition pos, BlockType type);
        void SetBlockUnsafe(ChunkPosition ch, BlockChunkPosition bl, BlockType type);
        void SetColumn(BlockWorldPosition highestPoint, BlockType type);
      //  void SetHeightMap();
        void Render();
    };
}

#endif //NAICRAFTYI_TERRAIN_H
