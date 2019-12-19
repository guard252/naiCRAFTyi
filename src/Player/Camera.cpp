#include "Camera.h"

namespace Craft
{
    Camera::Camera(const GL::ShaderProgram& _shader, glm::mat4 _view):
    shader{_shader}, view{_view}
    {

    }

    void Camera::SendViewToShader()const
    {
        shader.SetUniformMatr4f("u_View", view);
    }
}