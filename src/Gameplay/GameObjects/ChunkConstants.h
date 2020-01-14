#ifndef NAICRAFTYI_CHUNKCONSTANTS_H
#define NAICRAFTYI_CHUNKCONSTANTS_H
#include "ChunkTypedefs.h"

constexpr int CHUNK_SIZE   = 16;
constexpr int CHUNK_SQUARE = CHUNK_SIZE * CHUNK_SIZE;
constexpr int CHUNK_CUBE   = CHUNK_SIZE * CHUNK_SIZE * CHUNK_SIZE;


enum class BlockType
{
    AIR,
    DIRT,
    WOOD,
    LEAVES
};

constexpr int SQUARE_ATTR_COUNT = 24;
constexpr int VERTEX_ATTR_COUNT = SQUARE_ATTR_COUNT / 4;


//c - coordinate, b - block type, t - texture coordinates
//                           c  c  c  t  t  b  c  c  c  t  t  b  c  c  c  t  t  b  c  c  c  t  t  b
const MeshSquare LEFT_FACE  {0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0};
const MeshSquare RIGHT_FACE {1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0};
const MeshSquare TOP_FACE   {1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0};
const MeshSquare BOTTOM_FACE{0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0};
const MeshSquare FRONT_FACE {1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0};
const MeshSquare BACK_FACE  {0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};

#endif //NAICRAFTYI_CHUNKCONSTANTS_H
