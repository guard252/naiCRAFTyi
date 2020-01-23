#ifndef NAICRAFTYI_CHUNK_H
#define NAICRAFTYI_CHUNK_H
#include "ChunkMesh.h"
#include "Coordinates.h"
namespace Craft
{
    class Terrain;
    class Chunk
    {
        std::array<std::array<std::array<BlockType, CHUNK_SIZE>, CHUNK_SIZE>, CHUNK_SIZE> blocks;
        ChunkMesh mesh;
        std::array<Chunk*, 6> neighbors;
        Terrain* terrain;
        ChunkPosition position;
    public:
        void GenerateCubeChunk();
        Chunk(const GL::ShaderProgram& _shader, ChunkPosition chunkPosition, Terrain* ter);
        void Draw()const;
        void CreateMesh();
        BlockType GetBlock(int x, int y, int z)const;
        BlockType GetBlockUnsafe(int x, int y, int z)const;
    };
}

#endif //NAICRAFTYI_CHUNK_H
