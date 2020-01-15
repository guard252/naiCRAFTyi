#version 440 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texPosition;
layout(location = 2) in float texIndex;

uniform mat4 u_View;
uniform mat4 u_Proj;


out float v_TexIndex;
out vec2 v_TexPosition;
void main()
{
    gl_Position = u_Proj * u_View * vec4(position, 1.0);
    v_TexPosition = texPosition;
    v_TexIndex = texIndex;
}