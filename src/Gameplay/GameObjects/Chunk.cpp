#include "Chunk.h"

namespace Craft
{
    Chunk::Chunk(const GL::ShaderProgram& _shader) : mesh{_shader}
    {
        GenerateCubeChunk();
        mesh.GenerateMesh(blocks);
    }

    void Chunk::GenerateCubeChunk()
    {
        for(int x = 0; x < CHUNK_SIZE; x++)
        {
            for(int y = 0; y < CHUNK_SIZE; y++)
            {
                for(int z = 0; z < CHUNK_SIZE; z++)
                {
                    blocks[x][y][z] = BlockType::WOOD;
                }
            }
        }
    }

    void Chunk::Draw()
    {
        mesh.Render();
    }
}