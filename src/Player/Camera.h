#ifndef NAICRAFTYI_CAMERA_H
#define NAICRAFTYI_CAMERA_H
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "../GLAbstraction/ShaderProgram.h"

namespace Craft {
    class Camera {
    private:
        glm::mat4 view;
        const GL::ShaderProgram& shader;
    public:
        Camera(const GL::ShaderProgram& _shader, glm::mat4 _view = glm::mat4(1));
        const glm::mat4& GetView()const{ return view; }
        void SetView(const glm::mat4& mat){ view = mat; }
        void TranslateView(const glm::vec3 translation)
        {
            view = glm::translate(view, translation);
        }

        void SendViewToShader()const;
    };
}

#endif //NAICRAFTYI_CAMERA_H
