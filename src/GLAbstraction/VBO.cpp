#include "VBO.h"


GL::VBO::VBO(GLuint size, GLfloat *data) {
    GLCall(glGenBuffers(1, &rendererID));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, rendererID));
    GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW));
}

void GL::VBO::Bind() const {
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, rendererID));

}

void GL::VBO::UnBind() const {
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));

}

GL::VBO::~VBO() {
    GLCall(glDeleteBuffers(1, &rendererID));

}


