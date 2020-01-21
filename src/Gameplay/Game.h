#ifndef NAICRAFTYI_GAME_H
#define NAICRAFTYI_GAME_H
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "../Player/Controller.h"
#include "../Player/Camera.h"
#include "GameObjects/Terrain.h"
namespace Craft
{
    class Game
    {
    private:
        unsigned width{640}, height{480};
        GLFWwindow* window;

    private:
        GL::ShaderProgram blockShader{"../shaders/vertex.vert", "../shaders/fragment.frag"};
        Camera camera;
        Controller controller;
        glm::mat4 projection{glm::perspective(glm::radians(60.0f), (float)width/(float)height, 0.1f, 10.0f)};
        GL::ArrayTexture texPack;
    private:
        void ChangeProjectionOnResize(GLFWwindow* window);
    public:
        Game(GLFWwindow * window);
        int Run();

    };
}

#endif //NAICRAFTYI_GAME_H
