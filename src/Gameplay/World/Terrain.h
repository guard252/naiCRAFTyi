#ifndef NAICRAFTYI_TERRAIN_H
#define NAICRAFTYI_TERRAIN_H
#include "Chunk.h"
#include <map>
#include <unordered_map>


namespace Craft
{
    class Terrain
    {
        const GL::ShaderProgram& shader;
        ChunkTable chunks;
        std::unordered_map<std::pair<int, int>, glm::vec2, KeyFunctions> randVectors;
        const int TERRAIN_PRIMARY_WIDTH = 10;
        const int TERRAIN_PRIMARY_LENGTH = 10;
        const int TERRAIN_DEPTH = 10;
    private:
        void GenerateWorldWithPerlinNoise();
        void GenerateRandomVectors();
    public:
        Terrain(const GL::ShaderProgram& _shader);
        ~Terrain();
        void GeneratePlaneWorld();
        BlockType GetBlock(BlockWorldPosition position);
        BlockType GetBlock(ChunkPosition ch, BlockChunkPosition bl);
        void Render();
    };
}

#endif //NAICRAFTYI_TERRAIN_H
