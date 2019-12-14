#include "CubeModel.h"

namespace Craft {
    // For now lets just assume that blocks will only have maximum 3 textures
    // to be drawn with until we start rendering world using chunks
    CubeModel::CubeModel(const GL::Texture& _side, const GL::Texture& _top,  const GL::Texture& _bot): Model(),
    side{_side}, top{_top}, bot{_bot}
    {
        // slot 0 is sides, 1 is tob, 2 is bottom
        vertices = new float[216] { -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 0.0f,
                                     0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,
                                     0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,
                                     0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,
                                    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,
                                    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 0.0f,

                                    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f,
                                     0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,
                                     0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f,
                                     0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f,
                                    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f,
                                    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f,

                                    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f,
                                    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,
                                    -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,
                                    -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,
                                    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f,
                                    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f,

                                     0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f,
                                     0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,
                                     0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,
                                     0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,
                                     0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f,
                                     0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f,

                                    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 2.0f,
                                     0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 2.0f,
                                     0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 2.0f,
                                     0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 2.0f,
                                    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 2.0f,
                                    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 2.0f,

                                    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f,
                                     0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,
                                     0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f,
                                     0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f,
                                    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
                                    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f

         };
        buffer = new GL::VBO( 216 * sizeof(float), vertices);
        layout.Push<GLfloat>(3);
        layout.Push<GLfloat>(2);
        layout.Push<GLfloat>(1);
        vao.AddBuffer(*buffer, layout);


    }


    void CubeModel::Draw() {
        side.Bind(0);
        top.Bind(1);
        bot.Bind(2);
        buffer->Bind();
        vao.Bind();
        GLCall(glDrawArrays(GL_TRIANGLES, 0, 36));

    }
}
