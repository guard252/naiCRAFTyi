//
// Created by danylo on 11.12.19.
//
#include <iostream>
#include <cassert>
#include "ShaderProgram.h"

namespace GL
{
    ShaderProgram::ShaderProgram(std::string vertPath, std::string fragPath)
    {
        std::ifstream v_inp(vertPath);
        std::ifstream f_inp(fragPath);
        assert(v_inp.is_open() && f_inp.is_open());
        std::string v_source{std::istreambuf_iterator<char>(v_inp), std::istreambuf_iterator<char>()};
        std::string f_source{std::istreambuf_iterator<char>(f_inp), std::istreambuf_iterator<char>()};
        GLuint vertID = CompileShader(GL_VERTEX_SHADER, v_source);
        GLuint fragID = CompileShader(GL_FRAGMENT_SHADER, f_source);

        GLCall(rendererID = glCreateProgram());
        GLCall(glAttachShader(rendererID, vertID));
        GLCall(glAttachShader(rendererID, fragID));
        GLCall(glLinkProgram(rendererID));
        GLCall(glValidateProgram(rendererID));
        GLCall(glUseProgram(rendererID));
        GLCall(glDeleteShader(vertID));
        GLCall(glDeleteShader(fragID));
    }

    void ShaderProgram::Bind()
    {
        GLCall(glUseProgram(rendererID));
    }

    void ShaderProgram::UnBind()
    {
        GLCall(glUseProgram(0));
    }

    GLuint ShaderProgram::CompileShader(GLuint type, std::string source)
    {
        GLuint shaderID;
        GLCall(shaderID = glCreateShader(type));
        const char* src = source.c_str();
        GLCall(glShaderSource(shaderID, 1, &src, nullptr));
        GLCall(glCompileShader(shaderID));

        int success;
        char infoLog[512];
        glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
            std::cout << ((type == GL_VERTEX_SHADER) ? std::string("Vertex ") : std::string("Fragment ")) <<
            std::string("shader compilation error ") << infoLog << std::endl;
        }
        return shaderID;
    }



    ShaderProgram::~ShaderProgram()
    {
        GLCall(glDeleteProgram(rendererID));
    }

    void ShaderProgram::SetUniform1f(std::string name, GLfloat el) {
        GLint location = GetUniformLocation(name);
        if(location != -1)
        {
            GLCall(glUniform1f(location, el));
        }
    }

    void ShaderProgram::SetUniform2f(std::string name, GLfloat el1, GLfloat el2) {
        GLint location = GetUniformLocation(name);
        if(location != -1)
        {
            GLCall(glUniform2f(location, el1, el2));
        }
    }

    void ShaderProgram::SetUniform3f(std::string name, GLfloat el1, GLfloat el2, GLfloat el3) {
        GLint location = GetUniformLocation(name);
        if(location != -1)
        {
            GLCall(glUniform3f(location, el1, el2, el3));
        }
    }

    void ShaderProgram::SetUniform4f(std::string name, GLfloat el1, GLfloat el2, GLfloat el3, GLfloat el4) {
        GLint location = GetUniformLocation(name);
        if(location != -1)
        {
            GLCall(glUniform4f(location, el1, el2, el3, el4));
        }
    }

    void ShaderProgram::SetUniform1i(std::string name, GLint el) {
        GLint location = GetUniformLocation(name);
        if(location != -1)
        {
            GLCall(glUniform1i(location, el));
        }
    }

    void ShaderProgram::SetUniform2i(std::string name, GLint el1, GLint el2) {
        GLint location = GetUniformLocation(name);
        if(location != -1)
        {
            GLCall(glUniform2i(location, el1, el2));
        }
    }

    void ShaderProgram::SetUniform3i(std::string name, GLint el1, GLint el2, GLint el3) {
        GLint location = GetUniformLocation(name);
        if(location != -1)
        {
            GLCall(glUniform3i(location, el1, el2, el3));
        }
    }

    void ShaderProgram::SetUniform4i(std::string name, GLint el1, GLint el2, GLint el3, GLint el4) {
        GLint location = GetUniformLocation(name);
        if(location != -1)
        {
            GLCall(glUniform4i(location, el1, el2, el3, el4));
        }
    }

    void ShaderProgram::SetUniformMatr4f(std::string name, glm::mat4 matrix) {
        GLint location = GetUniformLocation(name);
        if(location != -1)
        {
            GLCall(glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]));
        }
    }

    GLint ShaderProgram::GetUniformLocation(std::string name) {
        std::unordered_map<std::string, GLint>::iterator it;
        if ((it = cachedUniforms.find(name)) == cachedUniforms.end()) {
            GLCall(GLint location = glGetUniformLocation(rendererID, name.c_str()));
            if (location != -1) it = cachedUniforms.insert(std::make_pair(name, location)).first;
            else std::cout << "No uniform found with name " << name << "\n";
        }
        return it->second;
    }
}