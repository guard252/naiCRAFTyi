#ifndef NAICRAFTYI_GAMEOBJECT_H
#define NAICRAFTYI_GAMEOBJECT_H
#include "glm/glm.hpp"
namespace Craft {
    class GameObject {
        glm::mat4 model;
    public:
        virtual void Draw() = 0;
        virtual void SetModel(const glm::mat4& _model){ model = _model; }
        const glm::mat4& GetModel()const { return model; };
        virtual ~GameObject();
    };
}

#endif //NAICRAFTYI_GAMEOBJECT_H
