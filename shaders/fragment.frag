#version 440 core

in vec2 v_TexPosition;
in float v_TexIndex;

uniform sampler2DArray slot;

out vec4 color;

void main()
{
   color = texture(slot, vec3(v_TexPosition, v_TexIndex));
}