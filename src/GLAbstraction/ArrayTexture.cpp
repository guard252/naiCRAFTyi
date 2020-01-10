#include "ArrayTexture.h"

namespace GL
{
    /* In this constructor you mast pass all
     * the paths to images that will be used as textures.
     * The sizes, format, depth and resolutions must be the same.
     */
    ArrayTexture::ArrayTexture(std::initializer_list<std::string> images)
    {
        if (images.size() == 0) throw std::runtime_error{"The initializer list must contain at least one member"};
        GLCall(glGenTextures(1, &rendererID));
        GLCall(glActiveTexture(GL_TEXTURE0));
        GLCall(glBindTexture(GL_TEXTURE_2D_ARRAY, rendererID));

        GLCall(glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
        GLCall(glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
        GLCall(glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
        GLCall(glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

        stbi_set_flip_vertically_on_load(true);
        pixelData = stbi_load(images.begin()->c_str(), &width, &height, &BPP, 4);
        if (pixelData == nullptr) throw std::runtime_error("Can not load the image by the path " + *images.begin());

        GLCall(glTexStorage3D(GL_TEXTURE_2D_ARRAY, 5, GL_RGBA8, width, height, 256));
        GLCall(glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, nextSpot++,
                width, height, 1, GL_RGB, GL_UNSIGNED_BYTE, pixelData));
        stbi_image_free(pixelData);

        for(auto i = images.begin() + 1; i < images.end(); i++)
        {
            pixelData = stbi_load(images.begin()->c_str(), &width, &height, &BPP, 4);
            if (pixelData == nullptr) throw std::runtime_error("Can not load the image by the path " + *images.begin());

            GLCall(glBindTexture(GL_TEXTURE_2D_ARRAY, rendererID));
            GLCall(glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, nextSpot++,
                                   width, height, 1, GL_RGB, GL_UNSIGNED_BYTE, pixelData));
            stbi_image_free(pixelData);
        }

    }


    ArrayTexture::~ArrayTexture()
    {
        GLCall(glDeleteTextures(1, &rendererID));
    }

    void ArrayTexture::Bind(GLuint slot) const
    {
        GLCall(glActiveTexture(GL_TEXTURE0 + slot));
        GLCall(glBindTexture(GL_TEXTURE_2D_ARRAY, rendererID));
    }

    void ArrayTexture::UnBind() const
    {
        GLCall(glBindTexture(GL_TEXTURE_2D_ARRAY, 0));
    }
}
