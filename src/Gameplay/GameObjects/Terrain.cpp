#include "Terrain.h"

namespace Craft
{
    Terrain::Terrain(const GL::ShaderProgram& _shader) : shader{ _shader }
    {
        GeneratePlaneWorld();
    }
    Terrain::~Terrain()
    {
        for(auto& a : chunks)
        {
            delete a.second;
        }

    }
    void Terrain::GeneratePlaneWorld()
    {
        for(int x = 0; x < 10; x++)
        {
            for(int z = 0; z < 10; z++)
            {
                ChunkPosition a(x + 1, 1, z + 1);
                Chunk* c = new Chunk(shader, a, this);
                chunks.insert(std::make_pair(a, c));
            }
        }

        for(int x = 1; x < 11; x++)
        {
            for(int z = 1; z < 11; z++)
            {
                auto a = chunks.find(glm::vec3(x, 1, z));
                a->second->CreateMesh();
            }
        }
    }

    void Terrain::FillNeighbors(int x, int y, int z, std::array<Chunk*, 6>& neighbors)
    {
        ChunkTable::iterator neighbor;
        memset(&neighbors[0], 0, neighbors.size() * sizeof(Chunk*));
        if((neighbor = chunks.find(glm::vec3((x == 1) ? -1 : x - 1, y, z))) != chunks.end())
        {
            neighbors[0] = neighbor->second;
        }
        if((neighbor = chunks.find(glm::vec3((x == -1) ? 1 : x + 1, y, z))) != chunks.end())
        {
            neighbors[1] = neighbor->second;
        }
        if((neighbor = chunks.find(glm::vec3(x, (y == 1) ? -1 : y - 1, z))) != chunks.end())
        {
            neighbors[2] = neighbor->second;
        }
        if((neighbor = chunks.find(glm::vec3(x, (y == -1) ? 1 : y + 1, z))) != chunks.end())
        {
            neighbors[3] = neighbor->second;
        }
        if((neighbor = chunks.find(glm::vec3(x, y, (z == 1) ? -1 : z - 1))) != chunks.end())
        {
            neighbors[4] = neighbor->second;
        }
        if((neighbor = chunks.find(glm::vec3(x, y, (z == -1) ? 1 : z + 1))) != chunks.end())
        {
            neighbors[5] = neighbor->second;
        }
    }

    void Terrain::Render()
    {
        for(auto& a : chunks)
        {
            a.second->Draw();
        }
    }

    BlockType Terrain::GetBlock(BlockWorldPosition pos)
    {
        ChunkPosition chunkPos = GetChunkPos(pos);

        ChunkTable::iterator currentChunk;
        if(((currentChunk = chunks.find(chunkPos)) != chunks.end()))
        {
            BlockChunkPosition blockPos = GetBlockLocalPos(pos);
            return currentChunk->second->GetBlock(blockPos.x, blockPos.y, blockPos.z);
        }
        return BlockType::AIR;
    }
}