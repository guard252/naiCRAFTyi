#ifndef NAICRAFTYI_CHUNK_H
#define NAICRAFTYI_CHUNK_H
#include "ChunkMesh.h"

namespace Craft
{
    class Chunk
    {
        BlockType blocks[CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];
        ChunkMesh mesh;
    public:
        void GenerateCubeChunk();
        Chunk(const GL::ShaderProgram& _shader);
        void Draw();

    };
}

#endif //NAICRAFTYI_CHUNK_H
