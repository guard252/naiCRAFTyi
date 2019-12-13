#version 440 core

out vec4 color;
in vec2 v_TexPosition;
uniform sampler2D slot;
void main()
{
    color = texture(slot, v_TexPosition);
}