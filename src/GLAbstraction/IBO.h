#ifndef NAICRAFTYI_IBO_H
#define NAICRAFTYI_IBO_H
#include "Tools.h"

namespace GL
{
    class IBO
    {
    private:
        GLuint rendererID;
    public:
        IBO(){}
        IBO(GLuint count, const GLuint *data);
        IBO(const IBO&) = delete;
        void GenerateBuffer(GLuint count, const GLuint *data);
        void UpdateBuffer(GLuint count, const GLuint *data);
        void Bind() const;

        void UnBind() const;

        ~IBO();
    };
}

#endif //NAICRAFTYI_IBO_H
