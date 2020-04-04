#include <iostream>
#include "Gameplay/Game.h"
int main()
{
    GLFWwindow* window;

    if (!glfwInit()) {
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(1920, 1080, "naiCRAFTyi", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMaximizeWindow(window);
    glfwMakeContextCurrent(window);
    glewInit();

    Craft::Game mineCraft(window);
    mineCraft.Run();

    glfwTerminate();

}
