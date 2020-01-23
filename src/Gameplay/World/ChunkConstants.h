#ifndef NAICRAFTYI_CHUNKCONSTANTS_H
#define NAICRAFTYI_CHUNKCONSTANTS_H
#include "ChunkTypedefs.h"
namespace Craft
{
    constexpr int CHUNK_SIZE = 16;
    constexpr int CHUNK_SQUARE = CHUNK_SIZE * CHUNK_SIZE;
    constexpr int CHUNK_CUBE = CHUNK_SIZE * CHUNK_SIZE * CHUNK_SIZE;


    enum class BlockType
    {
        AIR, DIRT, WOOD, LEAVES, SAND, COBBLESTONE, BEDROCK
    };

    enum class TexIndex
    {
        DIRT, GRASS, GRASS_SIDE, WOOD_TOP, WOOD_SIDE, LEAVES, SAND, COBBLESTONE, BEDROCK
    };

    enum class BlockSide
    {
        LEFT, RIGHT, TOP, BOTTOM, FRONT, BACK
    };

    constexpr int SQUARE_ATTR_COUNT = 24;
    constexpr int VERTEX_ATTR_COUNT = SQUARE_ATTR_COUNT / 4;


    //c - coordinate, t - texture coordinates, i - index in the array texture
    //                                  c  c  c  t  t  i  c  c  c  t  t  i  c  c  c  t  t  i  c  c  c  t  t  i
    inline const MeshSquare LEFT_FACE  {0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0};
    inline const MeshSquare RIGHT_FACE {1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0};
    inline const MeshSquare TOP_FACE   {1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0};
    inline const MeshSquare BOTTOM_FACE{0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0};
    inline const MeshSquare FRONT_FACE {1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0};
    inline const MeshSquare BACK_FACE  {0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};

}
#endif //NAICRAFTYI_CHUNKCONSTANTS_H
