#ifndef NAICRAFTYI_VBLAYOUT_H
#define NAICRAFTYI_VBLAYOUT_H

#include <vector>
#include <cassert>
#include "Tools.h"

namespace GL {
    struct LayoutElement {
        GLuint count;
        GLuint type;
        GLuint normalized;

        GLuint GetTypeSize()const {
            switch (type) {
                case GL_FLOAT:
                    return sizeof(GLfloat);
                    break;
                case GL_UNSIGNED_INT:
                    return sizeof(GLuint);
                    break;
                case GL_UNSIGNED_BYTE:
                    return sizeof(GLubyte);
                    break;
                default:
                    assert(false);
            }
        }

    };

    class VBLayout {
    private:
        std::vector<LayoutElement> elements;
        GLuint stride{0};
    public:
        template<typename T>
        inline void Push(GLuint count, GLuint normalized = GL_FALSE)
        {
            assert(false);
        }



        GLuint GetStride() const { return stride; }

        const std::vector<LayoutElement> &GetElements() const { return elements; }
    };
    template<>
    inline void VBLayout::Push<GLfloat>(GLuint count, GLuint normalized) {
        elements.push_back(LayoutElement{count, GL_FLOAT, normalized});
        stride += count * elements.back().GetTypeSize();
    }

    template<>
    inline void VBLayout::Push<GLuint>(GLuint count, GLuint normalized) {
        elements.push_back(LayoutElement{count, GL_UNSIGNED_INT, normalized});
        stride += count * elements.back().GetTypeSize();
    }

    template<>
    inline void VBLayout::Push<GLubyte>(GLuint count, GLuint normalized) {
        elements.push_back(LayoutElement{count, GL_UNSIGNED_BYTE, normalized});
        stride += count * elements.back().GetTypeSize();
    }
}

#endif //NAICRAFTYI_VBLAYOUT_H
