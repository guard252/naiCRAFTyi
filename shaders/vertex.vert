#version 440 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texPosition;
layout(location = 2) in float slot;

uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Proj;

out float v_Slot;
out vec2 v_TexPosition;
void main()
{
    gl_Position = u_Proj * u_View * u_Model * position;
    v_TexPosition = texPosition;
    v_Slot = slot;

}