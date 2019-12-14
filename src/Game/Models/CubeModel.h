//
// Created by danylo on 13.12.19.
//

#ifndef NAICRAFTYI_CUBEMODEL_H
#define NAICRAFTYI_CUBEMODEL_H
#include "Model.h"
#include "../../GLAbstraction/Texture.h"
namespace Craft {
    class CubeModel : public Model {
    protected:
        float *vertices;
        const GL::Texture& side;
        const GL::Texture&  top;
        const GL::Texture&  bot;
    public:
        CubeModel(const GL::Texture& _side, const GL::Texture& _top, const GL::Texture& _bot);
        virtual void Draw();
    };
}

#endif //NAICRAFTYI_CUBEMODEL_H
