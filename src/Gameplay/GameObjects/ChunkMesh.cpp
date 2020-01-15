#include "ChunkMesh.h"

namespace Craft
{

    ChunkMesh::ChunkMesh(const GL::ShaderProgram &_shader) : shader{_shader}
    {
        layout.Push<float>(3); // screen coordinates
        layout.Push<float>(2); // texture coordinates
        layout.Push<float>(1); // texture index


    }

    void ChunkMesh::GenerateMesh(BlockType chunk[CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE])
    {
        GenerateVector(chunk);
        vbo.GenerateBuffer(sizeof(float) * mesh.size(), &mesh[0]);
        ibo.GenerateBuffer(indices.size(), &indices[0]);
        vao.Bind();
        vao.AddBuffer(vbo, layout);

    }

    void ChunkMesh::Render()
    {
        vbo.Bind();
        vao.Bind();
        ibo.Bind();
        shader.Bind();
        GLCall(glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0));
    }

    void ChunkMesh::GenerateVector(BlockType chunk[CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE])
    {
        for (int x = 0; x < CHUNK_SIZE; x++)
        {
            for (int y = 0; y < CHUNK_SIZE; y++)
            {
                for (int z = 0; z < CHUNK_SIZE; z++)
                {
                    BlockType currentBlock = chunk[x][y][z];
                    BlockPosition currentPos(x, y, z);
                    if (currentBlock != BlockType::AIR)
                    {

                        // Right face
                        if ((x + 1 == CHUNK_SIZE) || (x + 1 != CHUNK_SIZE && chunk[x + 1][y][z] == BlockType::AIR ||
                                                      chunk[x + 1][y][z] == BlockType::LEAVES))
                        {
                            AddFace(RIGHT_FACE, currentBlock, currentPos);
                        }

                        // Left face
                        if (!x ||
                            (x && chunk[x - 1][y][z] == BlockType::AIR || chunk[x - 1][y][z] == BlockType::LEAVES))
                        {
                            AddFace(LEFT_FACE, currentBlock, currentPos);
                        }

                        // Top face
                        if ((y + 1 == CHUNK_SIZE) || (y + 1 != CHUNK_SIZE && chunk[x][y + 1][z] == BlockType::AIR ||
                                                      chunk[x][y + 1][z] == BlockType::LEAVES))
                        {
                            AddFace(TOP_FACE, currentBlock, currentPos);
                        }

                        // Bottom face
                        if (!y ||
                            (y && chunk[x][y - 1][z] == BlockType::AIR || chunk[x - 1][y][z] == BlockType::LEAVES))
                        {
                            AddFace(BOTTOM_FACE, currentBlock, currentPos);
                        }

                        // Front face
                        if ((z + 1 == CHUNK_SIZE) || (z + 1 != CHUNK_SIZE && chunk[x][y][z + 1] == BlockType::AIR ||
                                                      chunk[x][y][z + 1] == BlockType::LEAVES))
                        {
                            AddFace(FRONT_FACE, currentBlock, currentPos);
                        }

                        // Back face
                        if (!z ||
                            (z && chunk[x][y][z - 1] == BlockType::AIR || chunk[x][y][z - 1] == BlockType::LEAVES))
                        {
                            AddFace(BACK_FACE, currentBlock, currentPos);
                        }
                    }
                }
            }
        }
    }


    void ChunkMesh::AddFace(const MeshSquare sq, BlockType type, BlockPosition position)
    {
        MeshSquare face;
        for (int i = 0; i < SQUARE_ATTR_COUNT; i++)
        {
            face[i] = sq[i];
        }
        GLuint index = GetTexIndex(sq, type);
        SetTexIndex(face, index);
        MoveBlockToPosition(face, position);
        mesh.insert(mesh.end(), std::begin(face), std::end(face));
        AddIndices();
    }

    /*
     * Since in ChunkConstants.h we define
     * texture index to be every sixth member of an array,
     * we'll just replace them with type passed in function argument
     */
    void ChunkMesh::SetTexIndex(MeshSquare sq, GLuint index)
    {
        for (int i = VERTEX_ATTR_COUNT - 1; i < SQUARE_ATTR_COUNT; i += VERTEX_ATTR_COUNT)
        {
            sq[i] = static_cast<float>(index);
        }
    }




    /*
     * Sets the basic MeshSquare data to a specific position in a chunk
     */
    void ChunkMesh::MoveBlockToPosition(MeshSquare sq, BlockPosition pos)
    {
        for (int i = 0; i < SQUARE_ATTR_COUNT; i += VERTEX_ATTR_COUNT)
        {
            sq[i] += pos.x;
            sq[i + 1] += pos.y;
            sq[i + 2] += pos.z;
        }
    }

    void ChunkMesh::AddIndices()
    {
        std::array<GLuint, 6> newIndices{lastAddedVertices + 0u, lastAddedVertices + 1u, lastAddedVertices + 2u,
                                         lastAddedVertices + 0u, lastAddedVertices + 2u, lastAddedVertices + 3u};
        indices.insert(indices.end(), newIndices.begin(), newIndices.end());
        lastAddedVertices += 4;
    }

    //TODO: find an adequate solution for this :)
    GLuint ChunkMesh::GetTexIndex(const MeshSquare sq, BlockType type)
    {
        switch (type)
        {
            case BlockType::DIRT:
            {
                if(sq == LEFT_FACE  ||
                   sq == RIGHT_FACE ||
                   sq == FRONT_FACE ||
                   sq == BACK_FACE)
                {
                    return static_cast<GLuint>(TexIndex::GRASS_SIDE);
                }
                if(sq == TOP_FACE)
                {
                    return static_cast<GLuint>(TexIndex::GRASS);
                }
                if(sq == BOTTOM_FACE)
                {
                    return static_cast<GLuint>(TexIndex::DIRT);
                }
                break;
            }
            case BlockType::LEAVES:
            {
                return static_cast<GLuint>(TexIndex::LEAVES);
            }
            case BlockType::BEDROCK:
            {
                return static_cast<GLuint>(TexIndex::BEDROCK);
            }
            case BlockType::COBBLESTONE:
            {
                return static_cast<GLuint>(TexIndex::COBBLESTONE);
            }
            case BlockType::WOOD:
            {
                if(sq == LEFT_FACE  ||
                   sq == RIGHT_FACE ||
                   sq == FRONT_FACE ||
                   sq == BACK_FACE)
                {
                    return static_cast<GLuint>(TexIndex::WOOD_SIDE);
                }
                if(sq == TOP_FACE  ||
                   sq == BOTTOM_FACE)
                {
                    return static_cast<GLuint>(TexIndex::WOOD_TOP);
                }
                break;
            }
            case BlockType::SAND:
            {
                return static_cast<GLuint>(TexIndex::SAND);
            }

        }

        throw std::runtime_error("There is no such texture with given parameters");
    }

}