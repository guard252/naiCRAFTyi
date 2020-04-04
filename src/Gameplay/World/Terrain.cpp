#include "Terrain.h"

std::default_random_engine Random::engine{};

namespace Craft
{
    Terrain::Terrain(const GL::ShaderProgram &_shader) : shader{_shader}
    {
        std::thread world_generation_thread(&Terrain::CreateWorld, this);

        //CreateWorld();
        world_generation_thread.join();
    }

    Terrain::~Terrain()
    {
        for (auto &a : chunks)
        {
            delete a.second;
        }

    }

    void Terrain::CreateWorld()
    {
        for (int x = 1; x < TERRAIN_PRIMARY_WIDTH + 1; x++)
        {
            for (int y = 1; y < TERRAIN_DEPTH + 1; y++)
            {
                for (int z = 1; z < TERRAIN_PRIMARY_LENGTH + 1; z++)
                {
                    ChunkPosition a(x, y, z);
                    Chunk *c = new Chunk(shader, a, this);
                    chunks.insert(std::make_pair(a, c));
                }
            }
        }
        GenerateSmoothWorld();
        for (int x = 1; x < TERRAIN_PRIMARY_WIDTH + 1; x++)
        {
            for (int y = 1; y < TERRAIN_DEPTH + 1; y++)
            {
                for (int z = 1; z < TERRAIN_PRIMARY_LENGTH + 1; z++)
                {
                    ChunkPosition a(x, y, z);
                    chunks.find(a)->second->CreateMesh();
                }
            }
        }


    }

    void Terrain::GenerateSmoothWorld()
    {
        int octavesCount = 5;
        float frequency = 2048;
        int amplitude = 128;

        heightMap = GenerateWorldHeightMap(TERRAIN_PRIMARY_WIDTH * CHUNK_SIZE, TERRAIN_PRIMARY_LENGTH * CHUNK_SIZE,
                frequency/=2, amplitude/=2);
        for(int i = 0; i < octavesCount - 1; i++)
        {
            heightMap = AddHeightMaps(heightMap,
                    GenerateWorldHeightMap(TERRAIN_PRIMARY_WIDTH * CHUNK_SIZE, TERRAIN_PRIMARY_LENGTH * CHUNK_SIZE,
                            frequency/=2, amplitude/=2));
        }
        //heightMap = GenerateWorldHeightMap(TERRAIN_PRIMARY_WIDTH * CHUNK_SIZE, TERRAIN_PRIMARY_LENGTH * CHUNK_SIZE);
        for (int x = 0; x < TERRAIN_PRIMARY_WIDTH * CHUNK_SIZE; x++)
        {
            for (int z = 0; z < TERRAIN_PRIMARY_LENGTH * CHUNK_SIZE; z++)
            {
                SetColumn(BlockWorldPosition{x, heightMap[x][z], z}, BlockType::DIRT);
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

    void Terrain::SetBlockUnsafe(BlockWorldPosition pos, BlockType type)
    {
        ChunkPosition ch = GetChunkPos(pos);
        BlockChunkPosition bl = GetBlockLocalPos(pos);
        ChunkTable::iterator it;
        chunks.find(ch)->second->SetBlock(bl, type);
    }

    void Terrain::SetBlockUnsafe(ChunkPosition ch, BlockChunkPosition bl, BlockType type)
    {
        ChunkTable::iterator it;
        chunks.find(ch)->second->SetBlock(bl, type);
    }

    void Terrain::SetColumn(BlockWorldPosition highestPoint, BlockType type)
    {
        ChunkPosition ch = GetChunkPos(highestPoint);
        BlockChunkPosition bl = GetBlockLocalPos(highestPoint);
        do
        {
            chunks.find(ch)->second->SetColumn(bl, type);
            bl.y = CHUNK_SIZE - 1;
        } while(--ch.y && chunks.find(ch) != chunks.end());


    }
}