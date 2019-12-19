//
// Created by danylo on 19.12.19.
//

#include "Game.h"

namespace Craft
{
    Game::Game(): camera(blockShader, glm::translate(glm::mat4(1), glm::vec3(0, 0, -5)))
    {

    }

    int Game::Run(GLFWwindow* window)
    {


        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);

        Craft::DirtBlock block(blockShader, glm::vec3(0, 0, 0));
        while (!glfwWindowShouldClose(window))
        {
            blockShader.Bind();
            blockShader.SetUniformMatr4f("u_Proj", projection);
            camera.SendViewToShader();

            glEnable(GL_DEPTH_TEST);
            GLCall(glClearColor(0.2, 0.6, 1.0, 1.0));
            GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

            block.Draw();

            glfwSwapBuffers(window);
            glfwPollEvents();
        }

    }
}
