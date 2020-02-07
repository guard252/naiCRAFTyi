#include "Chunk.h"
#include "Terrain.h"

namespace Craft
{
    Chunk::Chunk(const GL::ShaderProgram &_shader, ChunkPosition pos, Terrain *ter) : mesh{_shader, pos}, terrain{ter},
                                                                                      position{pos}
    {
        GenerateCubeChunk();
    }

    void Chunk::GenerateCubeChunk()
    {
        for (int x = 0; x < CHUNK_SIZE; x++)
        {
            for (int y = 0; y < CHUNK_SIZE; y++)
            {
                for (int z = 0; z < CHUNK_SIZE; z++)
                {
                    blocks[x][y][z] = BlockType::AIR;
                }
            }
        }

     //  memset(&blocks[0][0][0], 0, blocks.size() * sizeof(BlockType));
    }

    void Chunk::CreateMesh()
    {
        for (int x = 0; x < CHUNK_SIZE; x++)
        {
            for (int y = 0; y < CHUNK_SIZE; y++)
            {
                for (int z = 0; z < CHUNK_SIZE; z++)
                {
                    BlockType currentBlock = blocks[x][y][z];
                    BlockChunkPosition currentPos(x, y, z);
                    if (currentBlock != BlockType::AIR)
                    {

                            // Right face
                            if (GetBlock(x + 1, y, z) == BlockType::AIR || GetBlock(x + 1, y, z) == BlockType::LEAVES)
                            {
                                mesh.AddFace(RIGHT_FACE, currentBlock, currentPos);
                            }

                            // Left face
                            if (GetBlock(x - 1, y, z) == BlockType::AIR || GetBlock(x - 1, y, z) == BlockType::LEAVES)
                            {
                                mesh.AddFace(LEFT_FACE, currentBlock, currentPos);
                            }

                            // Top face
                            if (GetBlock(x, y + 1, z) == BlockType::AIR || GetBlock(x, y + 1, z) == BlockType::LEAVES)
                            {
                                mesh.AddFace(TOP_FACE, currentBlock, currentPos);
                            }

                            // Bottom face
                            if (GetBlock(x, y - 1, z) == BlockType::AIR || GetBlock(x, y - 1, z) == BlockType::LEAVES)
                            {
                                mesh.AddFace(BOTTOM_FACE, currentBlock, currentPos);
                            }

                            // Front face
                            if (GetBlock(x, y, z + 1) == BlockType::AIR || GetBlock(x, y, z + 1) == BlockType::LEAVES)
                            {
                                mesh.AddFace(FRONT_FACE, currentBlock, currentPos);
                            }

                            // Back face
                            if (GetBlock(x, y, z - 1) == BlockType::AIR || GetBlock(x, y, z - 1) == BlockType::LEAVES)
                            {
                                mesh.AddFace(BACK_FACE, currentBlock, currentPos);
                            }


                    }
                }
            }
        }
        mesh.GenerateMesh();
    }

    BlockType Chunk::GetBlock(int x, int y, int z) const
    {
        if (x < 0 || y < 0 || z < 0 || x >= CHUNK_SIZE || y >= CHUNK_SIZE || z >= CHUNK_SIZE)
        {
           //return BlockType::AIR;
           return terrain->GetBlock(position, BlockChunkPosition(x, y, z));
        }
        return blocks[x][y][z];
    }
    BlockType Chunk::GetBlockUnsafe(int x, int y, int z)const
    {
        return blocks[x][y][z];
    }

    void Chunk::SetBlock(BlockChunkPosition pos, BlockType type)
    {
        blocks[pos.x][pos.y][pos.z] = type;
    }

    void Chunk::SetColumn(BlockChunkPosition highestPoint, BlockType type)
    {
        for(; highestPoint.y  >= 0; highestPoint.y--)
        {
            SetBlock(highestPoint, type);
        }
    }

    void Chunk::Draw()const
    {
        mesh.Render();
    }

}