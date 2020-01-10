#ifndef TOOLS_H
#define TOOLS_H

#include "GL/glew.h"
#include <iostream>
#include <iomanip>
#if defined(__GNUC__)
         #include <csignal>
         #define GLCall(x)\
         GLClearError();\
         x;\
         if(!GLLogCall()){\
         std::cout << " file: " << __FILE__ << "line: " << __LINE__ << " " << #x << std::endl;\
         raise(SIGTRAP);}
#elif defined(_MSC_VER)
         #define GLCall(x)\
         GLClearError();\
         x;\
         if(!GLLogCall()){\
         std::cout << #x << std::endl;\
         __debugbreak();}
#endif


void GLClearError();
bool GLLogCall();

#endif