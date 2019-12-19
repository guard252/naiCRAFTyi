#ifndef NAICRAFTYI_CONTROLLER_H
#define NAICRAFTYI_CONTROLLER_H
#include "Camera.h"
namespace Craft
{
    class Controller
    {
    private:
        Camera& camera;

    public:
        Controller(Camera& _camera) : camera{ _camera }{}

    };
}

#endif //NAICRAFTYI_CONTROLLER_H
