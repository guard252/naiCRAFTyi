#include "VBO.h"

namespace GL
{
    VBO::VBO(GLuint size, const GLfloat *data)
    {
        GLCall(glGenBuffers(1, &rendererID));
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, rendererID));
        GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW));
    }

    void VBO::Bind() const
    {
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, rendererID));

    }

    void VBO::UnBind() const
    {
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));

    }

    VBO::~VBO()
    {
        GLCall(glDeleteBuffers(1, &rendererID));
    }

    //The same as constructor
    void VBO::GenerateBuffer(GLuint size, GLfloat *data)
    {
        GLCall(glGenBuffers(1, &rendererID));
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, rendererID));
        GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW));
    }

    void VBO::UpdateBuffer(GLuint size, GLfloat *data)
    {
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, rendererID));
        GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW));
    }
}


