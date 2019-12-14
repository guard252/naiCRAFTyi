#ifndef NAICRAFTYI_TEXTURE_H
#define NAICRAFTYI_TEXTURE_H
#include "Tools.h"

namespace GL {
    class Texture {
    private:
        GLuint rendererID;
        int height, width, BPP;
        unsigned char* pixelData;

    public:
        Texture(std::string filename);
        void Bind(GLuint slot = 0)const;
        void UnBind()const;
        ~Texture();
    };
}

#endif //NAICRAFTYI_TEXTURE_H
