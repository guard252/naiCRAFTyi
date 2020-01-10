#ifndef NAICRAFTYI_CONTROLLER_H
#define NAICRAFTYI_CONTROLLER_H
#include "Camera.h"
#include "GLFW/glfw3.h"

#define keys
namespace Craft
{
    class Game;
    class Controller
    {
    private keys:
        int key_forward{GLFW_KEY_W};
        int key_back{GLFW_KEY_S};
        int key_left{GLFW_KEY_A};
        int key_right{GLFW_KEY_D};
        int key_jump{GLFW_KEY_SPACE};

        int key_escape{GLFW_KEY_ESCAPE};
    private:
        float step{0.05};
        float mouse_sensitivity{0.1};
        float yaw{0}, pitch{0};
        double cursor_x, cursor_y;

        bool cursor_isHidden{true};

        Camera& camera;
    private:
        static void ReturnCursor(GLFWwindow *window, Controller* user);
    public:
        void HandleEvents(GLFWwindow* window);
        Controller(Camera& _camera, GLFWwindow* window);
        void SetPrimarySettings(GLFWwindow* window);
        void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);


    };
}

#endif //NAICRAFTYI_CONTROLLER_H
