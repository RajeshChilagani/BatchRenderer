#include "BRLayer.h"

#include <array>

#include "GL-Core/Renderer/Renderer.h"
#include "GL-Core/Renderer/Utils.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glfw/include/GLFW/glfw3.h"

BRLayer::BRLayer() :Layer("BRLayer"), m_CameraController((uint32_t)1280,720,true)
{
	std::cout << "BRLayer Created" << std::endl;
}
BRLayer::~BRLayer()
{
	std::cout << "BRLayer Destroyed" << std::endl;
}

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

	GLCore::Renderer::Init();

}

void BRLayer::OnDetach()
{
}

void BRLayer::OnUpdate(GLCore::Timestep dt)
{
	//LOG_INFO("BRLayer: Update");
	glClearColor(m_BGColor.x,m_BGColor.y, m_BGColor.z,m_BGColor.w);
	GLCore::Renderer::Clear(GL_COLOR_BUFFER_BIT);

	m_CameraController.OnUpdate(dt);

	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(m_ApplePosition[0], m_ApplePosition[1], 0.0f));

	m_Shader->Bind();

	GLCore::Renderer::ResetStats();
	GLCore::Renderer::BeginBatch(m_CameraController.GetCamera());
	m_Shader->SetUniformMat4f("u_VP", m_CameraController.GetCamera().GetViewProjectionMatrix());

	if (GLCore::Input::IsKeyPressed(GLCore::Key::A))
	{
		LOG_TRACE("{0} is Pressed", static_cast<char>(GLCore::Key::A));
	}

	GLCore::Renderer::DrawQuad({ -14.0f,14.0f }, { 5.0f,5.0f }, {1.0f,1.0f,1.0f,1.0f});

	static float i = 0;
	
	i += 0.01;//RandomInRange(1.0f,12.0f);
	if (i > 15)
		i = 0.0f;
	for(float y = i; y < 15; y+=1)
	{
		for(float x = i; x < 15; x+=1)
		{
			glm::vec4 color = {x/10,0.25f,y/10,1.0f};
			GLCore::Renderer::DrawQuad({ x,y }, { 1.0f,1.0f }, color);
		}
	}

	for(int y = 4; y < 12; y++)
	{
		for(int x = 4; x < 12; x++)
		{
			GLCore::Renderer::DrawQuad({ x,y}, { 1.0f,1.0f }, ((x + y) % 2 == 0 ? m_Textures[0] : m_Textures[1]));
		}
	}
	m_Shader->SetUniformMat4f("u_M", model);
	m_Shader->SetUniform1f("u_time", (float)glfwGetTime());

	GLCore::Renderer::Endbatch();
	
}

void BRLayer::ImGuiRender()
{
	ImGui::Begin("Debug");
	static bool show = true;
	//ImGui::ShowDemoWindow(&show);
	ImGui::ColorEdit4("BackgroundColor",(float*)&m_BGColor);
	ImGui::DragFloat2("Move Textures", m_ApplePosition,0.01f);
	ImGui::Text("Quads: %d", GLCore::Renderer::GetStats().QuadCount);
	ImGui::Text("DrawCalls: %d", GLCore::Renderer::GetStats().DrawCount);
	ImGui::End();
}

void BRLayer::OnEvent(GLCore::Event& e)
{
	//LOG_TRACE(e);
	m_CameraController.OnEvent(e);
}