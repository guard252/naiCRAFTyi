#include "Controller.h"
#include "../Gameplay/Game.h"

namespace Craft
{
    Controller::Controller(Camera& _camera, GLFWwindow *window) : camera{_camera }
    {
        SetPrimarySettings(window);
        glfwGetCursorPos(window, &cursor_x, &cursor_y);
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
        ReturnCursor(window, this);

    }

    // This one is not a callback because with callbacks
    // it doesn't work as smoothly
    void Controller::HandleEvents(GLFWwindow *window)
    {
        Controller *user = reinterpret_cast<Controller *>(glfwGetWindowUserPointer(window));

        //Player movement
        if (glfwGetKey(window, user->key_forward))
        {
            user->camera.TranslateView(glm::normalize(camera.GetForward()) * step);

        }
        else if (glfwGetKey(window, user->key_back))
        {
            user->camera.TranslateView(glm::normalize(-camera.GetForward()) * step);
        }

        if (glfwGetKey(window, user->key_left))
        {
            user->camera.TranslateView(-glm::normalize(glm::cross(camera.GetForward(), camera.GetUp())) * step);
        }
        else if (glfwGetKey(window, user->key_right))
        {
            user->camera.TranslateView(glm::normalize(glm::cross(camera.GetForward(), camera.GetUp())) * step);
        }
        
        // Mouse control
        if(cursor_isHidden)
        {
            double xpos, ypos;
            glfwGetCursorPos(window, &xpos, &ypos);
            float xoffset = xpos - cursor_x;
            float yoffset = cursor_y - ypos;

            xoffset *= mouse_sensitivity;
            yoffset *= mouse_sensitivity;

            yaw += xoffset;
            pitch += yoffset;

            if (pitch > 89.0f)
                pitch = 89.0f;
            if (pitch < -89.0f)
                pitch = -89.0f;

            glm::vec3 fwd;
            fwd.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
            fwd.y = sin(glm::radians(pitch));
            fwd.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
            camera.SetForward(glm::normalize(fwd));

            int startPosX, startPosY;
            int windowWidth, windowHeight;
            glfwGetWindowPos(window, &startPosX, &startPosY);
            glfwGetWindowSize(window, &windowWidth, &windowHeight);
            glfwSetCursorPos(window, cursor_x = startPosX + windowWidth / 2,
                             cursor_y = startPosY + windowHeight / 2);
        }


    }

    void Controller::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        Controller* user = reinterpret_cast<Controller*>(glfwGetWindowUserPointer(window));
        if(key == user->key_escape && action == GLFW_PRESS)
        {
            if(user->cursor_isHidden)
            {
                glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            }
            else
            {
                glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
                ReturnCursor(window, user);
            }
            user->cursor_isHidden = !user->cursor_isHidden;
        }
    }

    void Controller::SetPrimarySettings(GLFWwindow *window)
    {
        glfwSetWindowUserPointer(window, this);
        glfwSetKeyCallback(window, KeyCallback);
    }

    void Controller::ReturnCursor(GLFWwindow *window, Controller* user)
    {
        int startPosX, startPosY, windowWidth, windowHeight;
        glfwGetWindowPos(window, &startPosX, &startPosY);
        glfwGetWindowSize(window, &windowWidth, &windowHeight);
        glfwSetCursorPos(window, user->cursor_x = startPosX,
        user->cursor_y = startPosY);
    }
}

