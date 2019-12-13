//
// Created by danylo on 11.12.19.
//

#include "VAO.h"

GL::VAO::VAO() {
    GLCall(glGenVertexArrays(1, &rendererID));
    GLCall(glBindVertexArray(rendererID));
}

void GL::VAO::Bind() const {
    GLCall(glBindVertexArray(rendererID));
}

void GL::VAO::UnBind() const {
    GLCall(glBindVertexArray(0));
}

void GL::VAO::AddBuffer(const GL::VBO &buffer, const GL::VBLayout &layout) {
    buffer.Bind();
    Bind();
    GLuint nextIndex{0};
    GLuint offset{0};
    const auto &els = layout.GetElements();
    for (int i = 0; i < els.size(); i++) {
        GLCall(glEnableVertexAttribArray(nextIndex));
        GLCall(glVertexAttribPointer(nextIndex, els[i].count, els[i].type,
                                     els[i].normalized, layout.GetStride(), (const void *) offset));
        offset += els[i].count * els[i].GetTypeSize();
        nextIndex++;
    }
}

GL::VAO::~VAO() {
    GLCall(glDeleteVertexArrays(1, &rendererID));
}
