#include "Terrain.h"

namespace Craft
{
    Terrain::Terrain(const GL::ShaderProgram &_shader) : shader{_shader}
    {
        GeneratePlaneWorld();
    }

    Terrain::~Terrain()
    {
        for (auto &a : chunks)
        {
            delete a.second;
        }

    }

    void Terrain::GeneratePlaneWorld()
    {
        for (int x = 1; x < TERRAIN_PRIMARY_WIDTH; x++)
        {
            for (int y = 1; y < TERRAIN_DEPTH; y++)
            {
                for (int z = 1; z < TERRAIN_PRIMARY_LENGTH; z++)
                {
                    ChunkPosition a(x, y, z);
                    Chunk *c = new Chunk(shader, a, this);
                    chunks.insert(std::make_pair(a, c));
                }
            }
        }
        for (int x = 1; x < TERRAIN_PRIMARY_WIDTH; x++)
        {
            for (int y = 1; y < TERRAIN_DEPTH; y++)
            {
                for (int z = 1; z < TERRAIN_PRIMARY_LENGTH; z++)
                {
                    ChunkPosition a(x, y, z);
                    chunks.find(a)->second->CreateMesh();
                }
            }
        }


    }

    void Terrain::GenerateWorldWithPerlinNoise()
    {
        GenerateRandomVectors();
        for (int i = 1; i < TERRAIN_PRIMARY_WIDTH; i += 1)
        {
            for (int j = 1; j < TERRAIN_PRIMARY_LENGTH; j += 1)
            {

            }
        }
    }


    void Terrain::GenerateRandomVectors()
    {
        for (auto &a : chunks)
        {
            if (randVectors.find(std::make_pair(a.first.x, a.first.z)) == randVectors.end())
            {
                randVectors.insert(std::make_pair(std::make_pair(a.first.x, a.first.z),
                                                  glm::normalize(glm::vec2(rand(), rand()))));
            }
        }
    }

    void Terrain::Render()
    {
        for (auto &a : chunks)
        {
            a.second->Draw();
        }
    }

    BlockType Terrain::GetBlock(BlockWorldPosition pos)
    {
        ChunkPosition chunkPos = GetChunkPos(pos);

        ChunkTable::iterator currentChunk;
        if (((currentChunk = chunks.find(chunkPos)) != chunks.end()))
        {
            BlockChunkPosition blockPos = GetBlockLocalPos(pos);
            return currentChunk->second->GetBlock(blockPos.x, blockPos.y, blockPos.z);
        }
        return BlockType::AIR;
    }

    BlockType Terrain::GetBlock(ChunkPosition ch, BlockChunkPosition bl)
    {
        if (bl.x == -1)
        {
            ch.x--; // 1, -1
            bl.x = CHUNK_SIZE - 1;
        } else if (bl.x == CHUNK_SIZE)
        {
            ch.x++;
            bl.x = 0;
        }
        if (bl.y == -1)
        {
            ch.y--;
            bl.y = CHUNK_SIZE - 1;
        } else if (bl.y == CHUNK_SIZE)
        {
            ch.y++;
            bl.y = 0;
        }
        if (bl.z == -1)
        {
            ch.z--;
            bl.z = CHUNK_SIZE - 1;
        } else if (bl.z == CHUNK_SIZE)
        {
            ch.z++;
            bl.z = 0;
        }
        ChunkTable::iterator currentChunk;
        if ((currentChunk = chunks.find(ch)) != chunks.end())
        {
            return currentChunk->second->GetBlockUnsafe(bl.x, bl.y, bl.z);
        }

        return BlockType::AIR;

    }
}