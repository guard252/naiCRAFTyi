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
    private:
        void FillNeighbors(int x, int y, int z, std::array<Chunk*, 6>& neighbors);
    public:
        Terrain(const GL::ShaderProgram& _shader);
        ~Terrain();
        void GeneratePlaneWorld();
        BlockType GetBlock(BlockWorldPosition position);
        void Render();
    };
}

#endif //NAICRAFTYI_TERRAIN_H
