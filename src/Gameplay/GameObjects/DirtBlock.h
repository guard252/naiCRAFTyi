#ifndef NAICRAFTYI_DIRTBLOCK_H
#define NAICRAFTYI_DIRTBLOCK_H

#include <glm/gtc/matrix_transform.hpp>
#include "Block.h"

namespace Craft {
    class DirtBlock : public Block {
    protected:
        const GL::Texture top{"../textures/grass.png"};
        const GL::Texture side{"../textures/grass_side.png"};
        const GL::Texture bot{"../textures/ground.png"};
        CubeModel cube;
    public:
        DirtBlock(const GL::ShaderProgram& shader, glm::vec3 translation);
        virtual ~DirtBlock(){}
        virtual void Translate(const glm::vec3& translation)
        {
            model = glm::translate(model, translation);
        }
        virtual void Draw();
    };

}


#endif //NAICRAFTYI_DIRTBLOCK_H
