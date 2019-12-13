#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "GLAbstraction/Texture.h"
#include "glm/glm.hpp"
#include "GLAbstraction/Tools.h"
#include "GLAbstraction/VBO.h"
#include "GLAbstraction/VAO.h"
#include "GLAbstraction/ShaderProgram.h"
float vertices[] {  -0.5, -0.5, 0, 0,
                     0.5, -0.5, 1, 0,
                     0.5,  0.5, 1, 1,
                    -0.5, -0.5, 0, 0,
                    -0.5,  0.5, 0, 1,
                     0.5,  0.5, 1, 1};
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
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glewInit();
 //   GL::VAO vao1;
    GL::VAO vao;
    GL::VBLayout layout, layout1;
    GL::VBO buffer(sizeof vertices, vertices);
   // GL::VBO buffer1(sizeof vertices1, vertices1);
    GL::Texture tex("../textures/leaves.png");
    tex.Bind();
    layout.Push<GLfloat>(2);
    layout.Push<GLfloat>(2);
   // vao1.AddBuffer(buffer1, layout);
    vao.AddBuffer(buffer, layout);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    GL::ShaderProgram shader("../shaders/vertex.vert", "../shaders/fragment.frag");
    shader.Bind();
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
       // vao.Bind();
        shader.SetUniform1i("slot", 0);
      //  buffer1.Bind();
       // vao1.Bind();
     //   GLCall(glDrawArrays(GL_TRIANGLES, 0, 3));
        buffer.Bind();
        vao.Bind();
        GLCall(glDrawArrays(GL_TRIANGLES, 0, 6));

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
