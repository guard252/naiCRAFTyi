#ifndef NAICRAFTYI_CUBEMODEL_H
#define NAICRAFTYI_CUBEMODEL_H
#include "Model.h"
#include "../../GLAbstraction/Texture.h"
#include "../../GLAbstraction/ShaderProgram.h"

namespace Craft {
    class CubeModel : public Model {
    protected:
        float *vertices;
        const GL::Texture& side;
        const GL::Texture&  top;
        const GL::Texture&  bot;
        const GL::ShaderProgram& shader;
    public:
        CubeModel(const GL::Texture& _side, const GL::Texture& _top,
                  const GL::Texture& _bot, const GL::ShaderProgram& _shader);
        ~CubeModel();
        virtual void Draw()const;

    };
}

#endif //NAICRAFTYI_CUBEMODEL_H
