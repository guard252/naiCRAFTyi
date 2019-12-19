//
// Created by danylo on 12.12.19.
//

#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

GL::Texture::Texture(std::string filename) {
    GLCall(glGenTextures(1, &rendererID));
    GLCall(glBindTexture(GL_TEXTURE_2D, rendererID));

    stbi_set_flip_vertically_on_load(1);
    pixelData = stbi_load(filename.c_str(), &width, &height, &BPP, 4);
    assert(pixelData);
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
    GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, GL_FALSE, GL_RGBA, GL_UNSIGNED_BYTE, pixelData));
    GLCall(glBindTexture(GL_TEXTURE_2D, 0));

    if(pixelData) stbi_image_free(pixelData);
}

void GL::Texture::Bind(GLuint slot)const {
    GLCall(glActiveTexture(GL_TEXTURE0 + slot));
    GLCall(glBindTexture(GL_TEXTURE_2D, rendererID));
}

void GL::Texture::UnBind()const {
    GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}

GL::Texture::~Texture() {
    GLCall(glDeleteTextures(1, &rendererID));
}
