#include "Coordinates.h"

namespace Craft
{
    BlockWorldPosition ToWorldCoordinates(const ChunkPosition& ch,const BlockChunkPosition& bl)
    {
        return {((ch.x < 0) ? ch.x + 1 : ch.x - 1) * CHUNK_SIZE + bl.x,
                ((ch.y < 0) ? ch.y + 1 : ch.y - 1) * CHUNK_SIZE + bl.y,
                ((ch.z < 0) ? ch.z + 1 : ch.z - 1) * CHUNK_SIZE + bl.z};
    }

    ChunkPosition GetChunkPos(const BlockWorldPosition& pos)
    {
        int x = pos.x;
        int y = pos.y;
        int z = pos.z;
        return {
                x < 0 ? (x / CHUNK_SIZE - 1) : (x / CHUNK_SIZE + 1),
                y < 0 ? (y / CHUNK_SIZE - 1) : (y / CHUNK_SIZE + 1),
                z < 0 ? (z / CHUNK_SIZE - 1) : (z / CHUNK_SIZE + 1),
        };
    }

    BlockChunkPosition GetBlockLocalPos(const BlockWorldPosition& pos)
    {
        return {(CHUNK_SIZE + (pos.x % CHUNK_SIZE)) % CHUNK_SIZE,
                (CHUNK_SIZE + (pos.y % CHUNK_SIZE)) % CHUNK_SIZE,
                (CHUNK_SIZE + (pos.z % CHUNK_SIZE)) % CHUNK_SIZE};
    }
}