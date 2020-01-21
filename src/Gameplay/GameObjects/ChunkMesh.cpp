#include "ChunkMesh.h"
#include "Chunk.h"

namespace Craft
{

    ChunkMesh::ChunkMesh(const GL::ShaderProgram &_shader, ChunkPosition pos) :
    shader{_shader},
    chunkShifting{((pos.x  < 0) ? (pos.x + 1) : (pos.x - 1)) * CHUNK_SIZE,
                  ((pos.y  < 0) ? (pos.y + 1) : (pos.y - 1)) * CHUNK_SIZE,
                  ((pos.z  < 0) ? (pos.z + 1) : (pos.z - 1)) * CHUNK_SIZE,}
    {
        layout.Push<float>(3); // screen coordinates
        layout.Push<float>(2); // texture coordinates
        layout.Push<float>(1); // texture index


    }

    void ChunkMesh::GenerateMesh()
    {
        vbo.GenerateBuffer(sizeof(float) * mesh.size(), &mesh[0]);
        ibo.GenerateBuffer(indices.size(), &indices[0]);
        ibo.Bind();
        vao.Bind();
        vao.AddBuffer(vbo, layout);
    }

    void ChunkMesh::Render()
    {
        vbo.Bind();
        ibo.Bind();
        vao.Bind();
        shader.Bind();
        GLCall(glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0));
    }


    void ChunkMesh::AddFace(const MeshSquare sq, BlockType type, BlockChunkPosition position)
    {
        {
            MeshSquare face;
            memcpy(face, sq, sizeof(float) * SQUARE_ATTR_COUNT);
            GLuint index = GetTexIndex(sq, type);
            SetTexIndex(face, index);
            MoveBlockToPosition(face, position);
            mesh.insert(mesh.end(), std::begin(face), std::end(face));
            AddIndices();
        }
    }

    /*
     * Since in ChunkConstants.h we define
     * texture index to be every sixth member of an array,
     * we'll just replace them with type passed in function argument
     */
    void ChunkMesh::SetTexIndex(float *sq, GLuint index)
    {
        for (int i = VERTEX_ATTR_COUNT - 1; i < SQUARE_ATTR_COUNT; i += VERTEX_ATTR_COUNT)
        {
            sq[i] = static_cast<float>(index);
        }
    }


    /*
     * Sets the basic MeshSquare data to a specific position in a chunk
     */
    void ChunkMesh::MoveBlockToPosition(MeshSquare sq, BlockChunkPosition pos)
    {
        for (int i = 0; i < SQUARE_ATTR_COUNT; i += VERTEX_ATTR_COUNT)
        {
            sq[i] += pos.x + chunkShifting.x;
            sq[i + 1] += pos.y + chunkShifting.y;
            sq[i + 2] += pos.z + chunkShifting.z;
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
                if (sq == LEFT_FACE || sq == RIGHT_FACE || sq == FRONT_FACE || sq == BACK_FACE)
                {
                    return static_cast<GLuint>(TexIndex::GRASS_SIDE);
                }
                if (sq == TOP_FACE)
                {
                    return static_cast<GLuint>(TexIndex::GRASS);
                }
                if (sq == BOTTOM_FACE)
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
                if (sq == LEFT_FACE || sq == RIGHT_FACE || sq == FRONT_FACE || sq == BACK_FACE)
                {
                    return static_cast<GLuint>(TexIndex::WOOD_SIDE);
                }
                if (sq == TOP_FACE || sq == BOTTOM_FACE)
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
        throw std::runtime_error("Air");
    }

}