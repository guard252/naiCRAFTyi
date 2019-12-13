#version 440 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texPosition;

out vec2 v_TexPosition;
void main()
{
    gl_Position = position;
    v_TexPosition = texPosition;
}