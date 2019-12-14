#ifndef NAICRAFTYI_MODEL_H
#define NAICRAFTYI_MODEL_H
#include "../../GLAbstraction/VBO.h"
#include "../../GLAbstraction/VAO.h"
#include "../../GLAbstraction/VBLayout.h"
namespace Craft {
    class Model {
    protected:
        GL::VAO vao;
        GL::VBLayout layout;
        GL::VBO *buffer{nullptr};
    public:
        virtual void Draw() = 0;
        Model(){}
        virtual ~Model(){}
    };
}

#endif //NAICRAFTYI_MODEL_H
