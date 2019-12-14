#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "GLAbstraction/Texture.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "GLAbstraction/Tools.h"
#include "GLAbstraction/VBO.h"
#include "GLAbstraction/VAO.h"
#include "GLAbstraction/ShaderProgram.h"
#include "Game/Models/CubeModel.h"

float vertices[] { -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
                    0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
                    0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
                    0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
                   -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
                   -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

                   -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
                    0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
                    0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
                    0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
                   -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
                   -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

                   -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
                   -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
                   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
                   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
                   -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
                   -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

                    0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
                    0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
                    0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
                    0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
                    0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
                    0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

                   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
                    0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
                    0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
                    0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
                   -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
                   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

                   -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
                    0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
                    0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
                    0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
                   -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
                   -0.5f,  0.5f, -0.5f,  0.0f, 1.0f};
int main()
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()) {
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glewInit();
    GL::Texture side("../textures/grass_side.png");
    GL::Texture top("../textures/grass.png");
    GL::Texture bot("../textures/ground.png");
    Craft::CubeModel cube(side, top, bot);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glm::mat4 proj = glm::perspective(glm::radians(60.0f), (float)640/(float)480, 0.1f, 100.0f);
    glm::mat4 model = glm::mat4(1);
    glm::mat4 view = glm::translate(glm::mat4(1), glm::vec3(0, 0, -5));
    GL::ShaderProgram shader("../shaders/vertex.vert", "../shaders/fragment.frag");
    shader.Bind();
    while (!glfwWindowShouldClose(window))
    {
        float rotation = 0.0;
        model = glm::rotate(model, rotation+=0.05, glm::vec3(0.0f, 1.0f, 0.0f));
        glEnable(GL_DEPTH_TEST);
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shader.SetUniform1i("u_Slot0", 0);
        shader.SetUniform1i("u_Slot1", 1);
        shader.SetUniform1i("u_Slot2", 2);
        shader.SetUniformMatr4f("u_MVC", proj * view * model);
        cube.Draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
