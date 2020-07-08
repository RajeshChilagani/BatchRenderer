#include "BRLayer.h"

#include <array>

#include "glm/gtc/matrix_transform.hpp"

struct Vertex
{
	glm::vec3 Position;
	glm::vec4 Color;
	glm::vec2 TexCoord;
	float TexID;
};

//float vertices[] =
//{ -0.6f,-0.45f,0.0f, 0.1f,0.3f,0.5f,1.0f, 0.0f,0.0f, 0.0f,
//  -0.1f,-0.45f,0.0f, 0.5f,0.4f,0.3f,1.0f, 1.0f,0.0f, 0.0f,
//  -0.1f, 0.45f,0.0f, 0.1f,0.2f,0.2f,1.0f, 1.0f,1.0f, 0.0f,
//  -0.6f, 0.45f,0.0f, 0.1f,0.1f,0.5f,1.0f, 0.0f,1.0f, 0.0f,
//
//  0.1f,-0.45f,0.0f, 0.5f,0.3f,0.5f,1.0f, 0.0f,0.0f, 1.0f,
//  0.6f,-0.45f,0.0f, 0.5f,0.3f,0.5f,1.0f, 1.0f,0.0f, 1.0f,
//  0.6f, 0.45f,0.0f, 0.5f,0.3f,0.5f,1.0f, 1.0f,1.0f, 1.0f,
//  0.1f, 0.45f,0.0f, 0.5f,0.3f,0.5f,1.0f, 0.0f,1.0f, 1.0f
//
//}; 

const size_t MAXQuadCount = 25;
float iOffset = 0.0f;

static void CreateQuad(std::vector<Vertex>& target,glm::vec3 position, float texID)
{
	float size = 0.5f;
	target.push_back({ {position.x,-0.45+position.y,0.0f},{0.5f,0.3f,0.5f,1.0f},{0.0f,0.0f},texID });
	target.push_back({ {position.x+size,-0.45+position.y,0.0f},{0.5f,0.3f,0.5f,1.0f},{1.0f,0.0f},texID });
	target.push_back({ {position.x + size,0.45+position.y,0.0f},{0.5f,0.3f,0.5f,1.0f},{1.0f,1.0f},texID });
	target.push_back({ {position.x,0.45+position.y,0.0f},{0.5f,0.3f,0.5f,1.0f},{0.0f,1.0f},texID });
}

BRLayer::BRLayer() :Layer("BRLayer"),m_MVP(glm::mat4(1)),m_Zero("Textures/apple.png"),m_One("Textures/Google.png"){}
BRLayer::~BRLayer() {}

void BRLayer::OnAttach() 
{
	//glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	const size_t MAXVeretxCount = MAXQuadCount * 4;
	const size_t MAXIndexCount = MAXQuadCount * 6;
	
	//m_VB = std::make_unique<VertexBuffer>(vertexPositions, 8 * 10 * sizeof(float));
	m_VB = std::make_unique<VertexBuffer>(MAXVeretxCount * sizeof(Vertex));
	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(4);
	layout.Push<float>(2);
	layout.Push<float>(1);

	unsigned int indices[MAXIndexCount];
	unsigned int offset = 0;
	for (int i = 0; i < MAXIndexCount-5; i+=6)
	{
		indices[i]   = offset + 0;
		indices[i+1] = offset + 1;
		indices[i+2] = offset + 2;
					   
		indices[i+3] = offset + 2;
		indices[i+4] = offset + 3;
		indices[i+5] = offset + 0;

		offset += 4;
	}
	m_VA.AddBuffer(*(m_VB.get()),layout);
	m_IB = std::make_unique<IndexBuffer>(indices, MAXIndexCount);
	
	m_Zero.Bind();
	m_One.Bind(1);

	m_Shader = std::make_unique<Shader>("Assets/BasicTriangle.shader");
	m_Shader->Bind();
	int sample[2] = { 0,1};
	m_Shader->SetUniform1iv("u_Textures", 2, sample);
	m_MVP = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, -1.0f, 1.0f);

}

void BRLayer::OnDetach()
{

}

void BRLayer::OnUpdate()
{
	LOG_INFO("BRLayer: Update");
	glClearColor(m_BGColor.x,m_BGColor.y, m_BGColor.z,m_BGColor.w);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	m_Renderer.Clear(GL_COLOR_BUFFER_BIT);

	uint32_t indexCount = 0;
	std::vector<Vertex> verticesData;
	verticesData.reserve(MAXQuadCount * 4);
	Vertex* buffer = verticesData.data();
	
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			CreateQuad(verticesData, { i+iOffset,j+iOffset,0.0f }, (i + j) % 2);
			indexCount += 6;
		}
	}
	iOffset += 0.01;
	m_VB->SetData(0, verticesData.size() * sizeof(Vertex), verticesData.data());

	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(m_ApplePosition[0], m_ApplePosition[1], 0.0f));
	m_MVP = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, -1.0f, 1.0f) * model;

	m_Shader->Bind();
	m_Shader->SetUniformMat4f("u_MVP", m_MVP);
    //m_Shader->SetUniform4f("u_Color", 1.0f, 1.0f, 1.0f, 1.0f);
	
	
	m_Renderer.Draw(m_VA, *(m_IB.get()), *(m_Shader.get()));
}

void BRLayer::ImGuiRender()
{
	ImGui::Begin("Test");
	static bool show = true;
	//ImGui::ShowDemoWindow(&show);
	ImGui::ColorEdit4("Square Alternate Color",(float*)&m_BGColor);
	ImGui::DragFloat2("Move", m_ApplePosition,0.01f);
	ImGui::DragFloat2("Zoom", m_GooglePosition, 0.01f);
	ImGui::End();
}

void BRLayer::OnEvent(GLCore::Event& e)
{
	LOG_TRACE(e);
}