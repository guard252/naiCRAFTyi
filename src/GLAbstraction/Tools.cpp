#include "Tools.h"

void GLClearError()
{
    while(glGetError() != GL_NO_ERROR);
}

bool GLLogCall()
{
    GLenum errorCode;
    if((errorCode = glGetError()) == GL_NO_ERROR)
    {
        return true;
    }
    std::cout << "[OpenGL error] {" << errorCode << "} file: " << __FILE__ << "line: " << __LINE__ << " ";

    return false;
}

