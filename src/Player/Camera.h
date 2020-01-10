#ifndef NAICRAFTYI_CAMERA_H
#define NAICRAFTYI_CAMERA_H
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "../GLAbstraction/ShaderProgram.h"


namespace Craft {
    class Camera {
    private:
        glm::vec3 position{0, 0, 0};
        glm::vec3 forward{0, 0, -1};
        glm::vec3 up{0, 1, 0};
        glm::mat4 view;
        const GL::ShaderProgram& shader;
    public:
        Camera(const GL::ShaderProgram& _shader);
        Camera(const GL::ShaderProgram& _shader, const glm::vec3& _position,
                const glm::vec3& _forward, const glm::vec3& _up);
        const glm::mat4& GetView()const{ return view; }
        //void SetView(const glm::mat4& mat){ view = mat; }
        void TranslateView(const glm::vec3 translation)
        {
            position += translation;
            view = glm::lookAt(position, position + forward, up);
        }
        void MoveForward(glm::vec3 translation)
        {
           forward += translation;
           view = glm::lookAt(position, position + forward, up);
        }
        void SetForward(glm::vec3 fwd)
        {
            forward = fwd;
            view = glm::lookAt(position, position + forward, up);
        }
        const glm::vec3& GetForward()const { return forward; }
        const glm::vec3& GetPosition()const { return position; }
        const glm::vec3& GetUp()const { return up; }



        void SendViewToShader()const;
        friend class Controller;
    };
}

#endif //NAICRAFTYI_CAMERA_H
