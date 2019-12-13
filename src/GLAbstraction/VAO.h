#ifndef NAICRAFTYI_VAO_H
#define NAICRAFTYI_VAO_H
#include "Tools.h"
#include "VBLayout.h"
#include "VBO.h"
namespace GL {
    class VAO {
    private:
        GLuint rendererID;
       // GLuint nextIndex{0};
       // GLuint offset{0};
    public:
        VAO();
        void Bind()const;
        void UnBind()const;
        void AddBuffer(const VBO& buffer, const VBLayout& layout);
        ~VAO();



    };
}

#endif //NAICRAFTYI_VAO_H
