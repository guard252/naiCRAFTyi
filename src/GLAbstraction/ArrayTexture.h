#ifndef NAICRAFTYI_ARRAYTEXTURE_H
#define NAICRAFTYI_ARRAYTEXTURE_H
#include "Tools.h"
#include "stb_image.h"
#include <cassert>
#include <exception>
namespace GL
{
    /*
     * This class is an abstraction above the array texture
     * in OpenGL.
     * It makes same size multiple textures binding less
     * memory(slots) taking.
    */
    class ArrayTexture
    {
    protected:
        GLuint rendererID;
        int width, height, BPP;
        GLubyte* pixelData;
        GLuint nextSpot{0};
    public:
        ArrayTexture(std::initializer_list<std::string> images);
        virtual ~ArrayTexture();
        void Bind(GLuint slot = 0)const;
        void UnBind()const;
    };
}

#endif //NAICRAFTYI_ARRAYTEXTURE_H
