#ifndef NAICRAFTYI_GAME_H
#define NAICRAFTYI_GAME_H
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "../Player/Camera.h"
#include "GameObjects/DirtBlock.h"

namespace Craft
{
    class Game
    {
    private:
        unsigned width{640}, height{640};


    private:
        // TODO: Replace absolute path with relative
        GL::ShaderProgram blockShader{"/home/danylo/dev/naiCRAFTyi/shaders/vertex.vert", "/home/danylo/dev/naiCRAFTyi/shaders/fragment.frag"};
        Camera camera;
        glm::mat4 projection{glm::perspective(glm::radians(60.0f), (float)width/(float)height, 0.1f, 100.0f)};

    public:
        explicit Game();
        int Run(GLFWwindow* window);

    };
}

#endif //NAICRAFTYI_GAME_H
