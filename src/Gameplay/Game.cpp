#include "Game.h"

namespace Craft
{
    Game::Game(GLFWwindow* _window): camera(blockShader, glm::translate(glm::mat4(1), glm::vec3(0, 0, 0))),
    window{_window} ,controller{camera, _window}
    {
        glfwMaximizeWindow(window);
    }

    int Game::Run()
    {
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);
        controller.SetPrimarySettings(window);
        Craft::DirtBlock block(blockShader, glm::vec3(0, 0, 0));
        while (!glfwWindowShouldClose(window))
        {
            glEnable(GL_DEPTH_TEST);
            GLCall(glClearColor(0.2, 0.6, 1.0, 1.0));
            GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

            controller.KeyEventHandler(window);
            camera.SendViewToShader();
            ChangeProjectionOnResize(window);
            blockShader.Bind();
            blockShader.SetUniformMatr4f("u_Proj", projection);

            block.Draw();

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
            projection = glm::perspective(glm::radians(60.0f), (float)width / (float)height, 0.1f, 100.0f);
            glViewport(0, 0, width, height);
        }
    }
}
