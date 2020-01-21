#ifndef NAICRAFTYI_CHUNKMESH_H
#define NAICRAFTYI_CHUNKMESH_H
#include "../../GLAbstraction/VAO.h"
#include "../../GLAbstraction/VBLayout.h"
#include "../../GLAbstraction/VBO.h"
#include "../../GLAbstraction/IBO.h"
#include "../../GLAbstraction/ArrayTexture.h"

#include "../../GLAbstraction/ShaderProgram.h"
#include "ChunkConstants.h"
#include "ChunkTypedefs.h"

namespace Craft
{

    class ChunkMesh
    {
        std::vector<GLfloat> mesh;
        std::vector<GLuint> indices;
        GL::VAO vao;
        GL::VBO vbo;
        GL::IBO ibo;
        GL::VBLayout layout;
        const GL::ShaderProgram& shader;
        glm::vec3 chunkShifting;

    private:
        int lastAddedVertices{0};
    public:
        ChunkMesh(const GL::ShaderProgram& shader, ChunkPosition pos);
        void GenerateMesh();
        void Render();
        void AddFace(const MeshSquare sq, BlockType type, BlockChunkPosition position);
    private:
        void SetTexIndex(MeshSquare sq, GLuint index);
        GLuint GetTexIndex(const MeshSquare sq, BlockType type);
        void MoveBlockToPosition(MeshSquare sq, BlockChunkPosition pos);
        void AddIndices();
    };
}

#endif //NAICRAFTYI_CHUNKMESH_H
