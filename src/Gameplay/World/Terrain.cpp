#include "Terrain.h"

std::default_random_engine Random::engine{};

namespace Craft
{
    Terrain::Terrain(const GL::ShaderProgram &_shader) : shader{_shader}
    {
        GeneratePlaneWorld();
     //   GenerateSmoothWorld();
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
        heightMap = GenerateWorldHeightMap(TERRAIN_PRIMARY_WIDTH * CHUNK_SIZE, TERRAIN_PRIMARY_LENGTH * CHUNK_SIZE);
        for(int x = 0; x < TERRAIN_PRIMARY_WIDTH * CHUNK_SIZE; x++)
        {
            for(int z = 0; z < TERRAIN_PRIMARY_LENGTH * CHUNK_SIZE; z++)
            {
                SetColumn(BlockWorldPosition{x, heightMap[x][z], z}, BlockType::DIRT);
            }
        }
        /*GenerateRandomVectors();
        for (int i = 1; i < TERRAIN_PRIMARY_WIDTH + 1; i += 1)
        {
            for (int j = 1; j < TERRAIN_PRIMARY_LENGTH + 1; j += 1)
            {
                auto a = GenerateColumnHeightMap({i, j});
                heightMaps.insert(std::make_pair(ChunkPosition(i, 1, j), a));

            }
        }
        for (int i = 1; i < TERRAIN_PRIMARY_WIDTH + 1; i += 1)
        {
            for (int j = 1; j < TERRAIN_PRIMARY_LENGTH + 1; j += 1)
            {
                auto a = GenerateColumnHeightMap({i, j});
                heightMaps.insert(std::make_pair(ChunkPosition(i, 1, j), a));

            }
        }
        SetHeightMap();
*/
    }

    /*
     * Generates pseudo-random vectors for every chunk angle in terrain
     * Starting number of vectors will be:
     * (TERRAIN_PRIMARY_WIDTH + 1) * (TERRAIN_PRIMARY_HEIGHT + 1)
     */
   /* void Terrain::GenerateRandomVectors()
    {
        for (int i = 1; i < TERRAIN_PRIMARY_WIDTH + 2; i++)
        {
            for (int j = 1; j < TERRAIN_PRIMARY_LENGTH + 2; j++)
            {

                if (randVectors.find(std::make_pair(i, j)) == randVectors.end())
                {
                    randVectors.insert(std::make_pair(std::make_pair(i, j),
                                                      glm::vec2(Random::GetFloat(-0.5f, 0.5f),
                                                              Random::GetFloat(-0.5f, 0.5f))));
                }
            }
        }
    }

    HeightMap Terrain::GenerateColumnHeightMap(const glm::vec2 &column)
    {
        glm::vec2 top_left = randVectors.find(std::make_pair(column.x, column.y + 1))->second;
        glm::vec2 bottom_left = randVectors.find(std::make_pair(column.x, column.y))->second;
        glm::vec2 top_right = randVectors.find(std::make_pair(column.x + 1, column.y + 1))->second;
        glm::vec2 bottom_right = randVectors.find(std::make_pair(column.x + 1, column.y))->second;

        ChunkPosition chunk(column.x, 1, column.y);
        HeightMap heightMap;

        for (int i = 0; i < CHUNK_SIZE; i++)
        {
            for (int j = 0; j < CHUNK_SIZE; j++)
            {
                // Vectors, directed to the corners
                glm::vec2 to_top_left    (MapToZeroOne(top_left.x - i, CHUNK_SIZE - 1),
                        MapToZeroOne(top_left.y- j, CHUNK_SIZE - 1));
                glm::vec2 to_bottom_left (MapToZeroOne(bottom_left.x - i, CHUNK_SIZE - 1),
                        MapToZeroOne(bottom_left.y- j, CHUNK_SIZE - 1));
                glm::vec2 to_top_right   (MapToZeroOne(top_right.x - i, CHUNK_SIZE - 1),
                        MapToZeroOne(top_right.y- j, CHUNK_SIZE - 1));
                glm::vec2 to_bottom_right(MapToZeroOne(bottom_right.x - i, CHUNK_SIZE - 1),
                        MapToZeroOne(bottom_right.y- j, CHUNK_SIZE - 1));

                //Corner values
                float tlVal = glm::dot(to_top_left, top_left);
                float blVal = glm::dot(to_bottom_left, bottom_left);
                float trVal = glm::dot(to_top_right, top_right);
                float brVal = glm::dot(to_bottom_right, bottom_right);


                float a = blerp(tlVal, trVal, blVal, brVal, MapToZeroOne(i, CHUNK_SIZE - 1), MapToZeroOne(j, CHUNK_SIZE - 1));
                int res = MapToBlockPosition(a, CHUNK_SIZE);
                heightMap[i][j] = res;
            }
        }
        return heightMap;
    }

    void Terrain::SetHeightMap()
    {
        for (int i = 1; i < TERRAIN_PRIMARY_WIDTH + 1; i++)
        {
            for (int j = 1; j < TERRAIN_PRIMARY_LENGTH + 1; j++)
            {
                for (int x = 0; x < CHUNK_SIZE; x++)
                {
                    for (int z = 0; z < CHUNK_SIZE; z++)
                    {
                        int highest = heightMaps.find({i, 1, j})->second[x][z];
                        for(; highest >= 0; highest--)
                        SetBlockUnsafe({i, 1, j}, {x, highest,z}, BlockType::DIRT);
                    }
                }
            }
        }
    }*/

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
        chunks.find(ch)->second->SetColumn(bl, type);

    }
}