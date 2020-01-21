#include "Game.h"

namespace Craft
{
    Game::Game(GLFWwindow* _window): camera(blockShader),
    window{_window} ,controller{camera, _window},
    texPack{"../textures/dirt.png",
            "../textures/grass.png",
            "../textures/grass_side.png",
            "../textures/wood_top.png",
            "../textures/wood_side.png",
            "../textures/leaves.png",
            "../textures/sand.png",
            "../textures/cobblestone.png",
            "../textures/bedrock.png"}
    {
        glfwMaximizeWindow(window);
    }

    int Game::Run()
    {
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);
        controller.SetPrimarySettings(window);
        Terrain terrain(blockShader);
        blockShader.SetUniform1i("slot", 0);
        while (!glfwWindowShouldClose(window))
        {
            glEnable(GL_DEPTH_TEST);
            GLCall(glClearColor(0.2, 0.6, 1.0, 1.0));
            GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

            controller.HandleEvents(window);
            camera.SendViewToShader();
            ChangeProjectionOnResize(window);
            blockShader.Bind();
            blockShader.SetUniformMatr4f("u_Proj", projection);

            terrain.Render();

            glfwSwapBuffers(window);
            glfwPollEvents();
        }

    }

    void Game::ChangeProjectionOnResize(GLFWwindow* window)
    {
        int newHeight, newWidth;
        glfwGetWindowSize(window, &newWidth, &newHeight);
        if(width != newWidth || height != newHeight)
        {
            width = newWidth;
            height = newHeight;
            projection = glm::perspective(glm::radians(60.0f), (float)width / (float)height, 0.1f, 1000.0f);
            GLCall(glViewport(0, 0, width, height));
        }
    }
}
