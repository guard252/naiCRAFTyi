#ifndef NAICRAFTYI_SHADERPROGRAM_H
#define NAICRAFTYI_SHADERPROGRAM_H
#include "Tools.h"
#include <string>
#include <fstream>
#include <unordered_map>
#include <glm/glm.hpp>
namespace GL {
    class ShaderProgram {
    private:
        GLuint CompileShader(GLuint type, std::string source);
        GLint GetUniformLocation(std::string name)const;
    private:
        GLuint rendererID;
        mutable std::unordered_map<std::string, GLint> cachedUniforms{};
    public:
        ShaderProgram(std::string vertPath, std::string fragPath);
        void Bind()const;
        void UnBind()const;

        void SetUniform1f(std::string name, GLfloat el)const;
        void SetUniform2f(std::string name, GLfloat el1, GLfloat el2)const;
        void SetUniform3f(std::string name, GLfloat el1, GLfloat el2, GLfloat el3)const;
        void SetUniform4f(std::string name, GLfloat el1, GLfloat el2, GLfloat el3, GLfloat el4)const;
        void SetUniform1i(std::string name, GLint el)const;
        void SetUniform2i(std::string name, GLint el1, GLint el2)const;
        void SetUniform3i(std::string name, GLint el1, GLint el2, GLint el3)const;
        void SetUniform4i(std::string name, GLint el1, GLint el2, GLint el3, GLint el4)const;
        void SetUniformMatr4f(std::string name, glm::mat4 matrix)const;

        ~ShaderProgram();

    };



}


#endif //NAICRAFTYI_SHADERPROGRAM_H
