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

uniform float u_time;
uniform sampler2D u_Textures[32];

void main()
{
	vec4 color = v_Color;
	int index = int(v_TexIndex);
	for (int n = 1; n < 2; n++) {
		float i = float(n);
		color *= vec4(0.7 / i * sin(i * color.x + u_time + 0.3 * i) + 0.8, 0.4 / i * sin(color.y + u_time + 0.3 * i) + 1.6, 1.0, 1.0);
	}
	//o_color =  vec4(v_TexIndex, v_TexIndex, v_TexIndex,1.0);
	//color = vec4(0.7 / sin(color.y + u_time + 0.3) + 0.8, 0.4 / cos(color.x + u_time + 0.3) + 1.6, 1.0,1.0);
	o_Color = texture(u_Textures[index], v_TexCoord) * color;
};