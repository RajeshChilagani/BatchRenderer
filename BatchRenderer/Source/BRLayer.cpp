#include "BRLayer.h"

#include <array>

#include "GL-Core/Renderer/Renderer.h"
#include "glm/gtc/matrix_transform.hpp"

BRLayer::BRLayer() :Layer("BRLayer"),m_MVP(glm::mat4(1)){}
BRLayer::~BRLayer() {}

void BRLayer::OnAttach() 
{
	//glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	m_Textures.emplace_back(std::make_shared<Texture>("Textures/Google.png"));
	m_Textures.emplace_back(std::make_shared<Texture>("Textures/apple.png"));

	m_Shader = std::make_unique<Shader>("Assets/BasicTriangle.shader");
	m_Shader->Bind();
	int samplers[32];
	for (int i = 0; i < 32; ++i)
	{
		samplers[i] = i;
	}
	m_Shader->SetUniform1iv("u_Textures", 32, samplers);

	Renderer::Init();

	m_MVP = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, -1.0f, 1.0f);

}

void BRLayer::OnDetach()
{
	Renderer::ShutDown();
}

void BRLayer::OnUpdate()
{
	LOG_INFO("BRLayer: Update");
	glClearColor(m_BGColor.x,m_BGColor.y, m_BGColor.z,m_BGColor.w);
	Renderer::Clear(GL_COLOR_BUFFER_BIT);

	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(m_ApplePosition[0], m_ApplePosition[1], 0.0f));
	m_MVP = glm::ortho(0.0f, 40.0f, 0.0f, 30.0f, -1.0f, 1.0f) * model;

	m_Shader->Bind();

	Renderer::ResetStats();
	Renderer::BeginBatch();

	for(float y = 0; y < 5; y++)
	{
		for(float x = 0; x < 5; x++)
		{
			glm::vec4 color = {x/10,0.25f,y/10,1.0f};
			Renderer::DrawQuad({ x,y }, { 1.0f,1.0f }, color);
		}
	}

	/*for(int y = 0; y < 10; y++)
	{
		for(int x = 0; x < 10; x++)
		{
			Renderer::DrawQuad({ x+10,y+10}, { 1.0f,1.0f }, ((x + y) % 2 == 0 ? m_Textures[0] : m_Textures[1]));
		}
	}*/

	Renderer::Endbatch();
	m_Shader->SetUniformMat4f("u_MVP", m_MVP);

	Renderer::Flush();
}

void BRLayer::ImGuiRender()
{
	ImGui::Begin("Test");
	static bool show = true;
	//ImGui::ShowDemoWindow(&show);
	ImGui::ColorEdit4("BackgroundColor",(float*)&m_BGColor);
	ImGui::DragFloat2("Move Textures", m_ApplePosition,0.01f);
	ImGui::Text("Quads: %d", Renderer::GetStats().QuadCount);
	ImGui::Text("DrawCalls: %d", Renderer::GetStats().DrawCount);
	ImGui::End();
}

void BRLayer::OnEvent(GLCore::Event& e)
{
	LOG_TRACE(e);
}