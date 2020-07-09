#shader vertex
#version 450 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 a_Color;
layout(location = 2) in vec2 a_TexCoord;
layout(location = 3) in float a_TexIndex;

uniform mat4 u_MVP;

out vec4 v_Color;
out vec2 v_TexCoord;
out float v_TexIndex;

void main()
{
	v_Color = a_Color;
	v_TexCoord = a_TexCoord;
	v_TexIndex = a_TexIndex;
	gl_Position = u_MVP * position;
};

#shader fragment
#version 450 core

out vec4 o_Color;

in vec4 v_Color;
in vec2 v_TexCoord;
in float v_TexIndex;

uniform sampler2D u_Textures[32];
void main()
{
	int index = int(v_TexIndex);
	//o_color =  vec4(v_TexIndex, v_TexIndex, v_TexIndex,1.0);
	o_Color = texture(u_Textures[index], v_TexCoord) * v_Color;
};