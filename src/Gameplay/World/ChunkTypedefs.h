#ifndef NAICRAFTYI_CHUNKTYPEDEFS_H
#define NAICRAFTYI_CHUNKTYPEDEFS_H
#include "glm/glm.hpp"
#include "../../Others/KeyFunctions.h"

namespace Craft
{
    using ChunkPosition = glm::ivec3;

    // This one is not a glm::uvec because if we need to
    // access blocks in other chunks, we will sometimes need
    // negative values
    using BlockChunkPosition = glm::ivec3;

    using BlockWorldPosition = glm::ivec3;

    using MeshSquare = float[24];

    class Chunk;

    using ChunkTable = std::unordered_map<ChunkPosition, Chunk*, KeyFunctions, KeyFunctions>;

    using RandVectors = std::vector<std::unordered_map<glm::vec2, glm::vec2, KeyFunctions, KeyFunctions>>;

}


#endif //NAICRAFTYI_CHUNKTYPEDEFS_H
