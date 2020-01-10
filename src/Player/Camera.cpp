#include "Camera.h"

namespace Craft
{
    Camera::Camera(const GL::ShaderProgram& _shader):
    shader{_shader}
    {
        view = glm::lookAt(position, position + forward, up);
    }

    Camera::Camera(const GL::ShaderProgram& _shader, const glm::vec3& _position,
                   const glm::vec3& _forward, const glm::vec3& _up) :
                   shader{_shader},
                   position{ _position }, forward{_forward}, up{_up}
    {
        view = glm::lookAt(position, position + forward, up);
    }
    void Camera::SendViewToShader()const
    {
        shader.SetUniformMatr4f("u_View", view);
    }
}