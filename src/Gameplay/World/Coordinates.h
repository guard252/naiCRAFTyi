#ifndef NAICRAFTYI_COORDINATES_H
#define NAICRAFTYI_COORDINATES_H
#include "ChunkTypedefs.h"
#include "ChunkConstants.h"

namespace Craft
{
    BlockWorldPosition ToWorldCoordinates(const ChunkPosition& ch,const BlockChunkPosition& bl);
    ChunkPosition GetChunkPos(const BlockWorldPosition& pos);
    BlockChunkPosition GetBlockLocalPos(const BlockWorldPosition& pos);
}

#endif //NAICRAFTYI_COORDINATES_H
