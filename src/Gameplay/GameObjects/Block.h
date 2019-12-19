#ifndef NAICRAFTYI_BLOCK_H
#define NAICRAFTYI_BLOCK_H

#include "GameObject.h"
#include "../Models/CubeModel.h"
#include "../../GLAbstraction/Texture.h"
#include "../../GLAbstraction/ShaderProgram.h"

namespace Craft {
    class Block : public GameObject {
    protected:
        const GL::ShaderProgram& shader;
        double destructionTime{ 0 };
    public:
        Block(const GL::ShaderProgram& _shader): shader{ _shader } {}
        virtual void Draw() = 0;
        virtual ~Block(){}
    };
}

#endif //NAICRAFTYI_BLOCK_H
