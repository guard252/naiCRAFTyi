#include "DirtBlock.h"

namespace Craft {
    DirtBlock::DirtBlock(const GL::ShaderProgram& shader, glm::vec3 translation): Block(shader),  cube(side, top, bot, shader)
    {
        model = glm::translate(glm::mat4(1), translation);
    }
    void DirtBlock::Draw()
    {
        side.Bind(0);
        top.Bind(1);
        bot.Bind(2);
        shader.Bind();
        shader.SetUniformMatr4f("u_Model", model);
        cube.Draw();
    }
}