#version 440 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texPosition;
layout(location = 2) in float slot;

uniform mat4 u_MVC;
out float v_Slot;
out vec2 v_TexPosition;
void main()
{
    gl_Position = u_MVC * position;
    v_TexPosition = texPosition;
    v_Slot = slot;

}