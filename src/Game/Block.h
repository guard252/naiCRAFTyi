//
// Created by danylo on 13.12.19.
//

#ifndef NAICRAFTYI_BLOCK_H
#define NAICRAFTYI_BLOCK_H

#include "GameObject.h"

namespace Craft {
    class Block : public GameObject {
        double destructionTime{ 0 };
        float* vertices;
    public:
        virtual void Draw() = 0;
        virtual ~Block();
    };
}

#endif //NAICRAFTYI_BLOCK_H
