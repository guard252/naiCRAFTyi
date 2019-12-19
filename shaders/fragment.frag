#version 440 core
#define DELTA 1e-8

in vec2 v_TexPosition;
flat in float v_Slot;

uniform sampler2D u_Slot0;
uniform sampler2D u_Slot1;
uniform sampler2D u_Slot2;

out vec4 color;

void main()
{
    if(abs(v_Slot) < DELTA)
    {
        color = texture(u_Slot0, v_TexPosition);
    }
    else if(abs(v_Slot - 1.0) < DELTA)
    {
        color = texture(u_Slot1,  v_TexPosition);
    }
    else if(abs(v_Slot - 2.0) < DELTA)
    {
        color = texture(u_Slot2,  v_TexPosition);
    }
}