#include "IBO.h"

namespace GL
{
    IBO::IBO(GLuint count, const GLuint *data)
    {
        GLCall(glGenBuffers(1, &rendererID));
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID));
        GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW));
    }

    void IBO::GenerateBuffer(GLuint count, const GLuint *data)
    {
        GLCall(glGenBuffers(1, &rendererID));
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID));
        GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW));
    }

    void IBO::UpdateBuffer(GLuint count, const GLuint *data)
    {
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID));
        GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW));
    }

    void IBO::Bind() const
    {
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID));
    }

    void IBO::UnBind() const
    {
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
    }

    IBO::~IBO()
    {
        GLCall(glDeleteBuffers(1, &rendererID));
    }
}