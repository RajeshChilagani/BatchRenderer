#include "BRLayer.h"

#include <array>

#include "glm/gtc/matrix_transform.hpp"
#include "glfw/include/GLFW/glfw3.h"

#include "GL-Core/Renderer/Renderer.h"
#include "GL-Core/Renderer/Utils.h"
#include "GL-Core/Renderer/EditorCamera.h"


BRLayer::BRLayer() 
	: Layer("BRLayer")
	, m_EditorCamera(30.0f, 1.778f, 0.1f, 1000.0f)
	, m_CameraController(1280.f, 720.f, true)
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
	glClearColor(m_BGColor.x,m_BGColor.y, m_BGColor.z,m_BGColor.w);
	GLCore::Renderer::Clear(GL_COLOR_BUFFER_BIT);

	//m_CameraController.OnUpdate(dt);
	m_EditorCamera.OnUpdate(dt);

	m_Shader->Bind();
	GLCore::Renderer::ResetStats();
	GLCore::Renderer::BeginBatch(m_EditorCamera);
	//m_Shader->SetUniformMat4f("u_VP", m_CameraController.GetCamera().GetViewProjectionMatrix());
	m_Shader->SetUniformMat4f("u_VP", m_EditorCamera.GetViewProjection());

	if (GLCore::Input::IsKeyPressed(GLCore::Key::A))
	{
		LOG_TRACE("{0} is Pressed", static_cast<char>(GLCore::Key::A));
	}

	GLCore::Renderer::DrawQuad({m_SquarePosition[0],m_SquarePosition[1]}, glm::vec2(1.f,1.f), m_Textures[0]);

	/*static float i = 10;
	if (i <= 0)
		i = 10.0f;
	int counter = 0;
	for(float y = i; y > 0; y--)
	{
		counter++;
		for(float x = i; x > 0; x--)
		{
			glm::vec4 color = {x/10,0.25f,y/10,1.0f};
			GLCore::Renderer::DrawQuad({ x + m_BatchPosition[0],y + m_BatchPosition[1] }, { 1.0f,1.0f }, color);
		}
	}
	i -= 0.1f;*/


	/*for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			GLCore::Renderer::DrawQuad({ x + m_BatchPosition[0],y + m_BatchPosition[1] }, { 1.0f,1.0f }, ((x + y) % 2 == 0 ? m_Textures[0] : m_Textures[1]));
		}
	}
	*/
	m_Shader->SetUniform1f("u_time", (float)glfwGetTime());

	GLCore::Renderer::Endbatch();
	
}

void BRLayer::ImGuiRender()
{
	ImGui::Begin("Debug");
	static bool show = true;
	//ImGui::ShowDemoWindow(&show);
	ImGui::ColorEdit4("BackgroundColor",(float*)&m_BGColor);
	ImGui::DragFloat2("Move Batch", m_BatchPosition,0.01f);
	ImGui::DragFloat2("Move Square", m_SquarePosition, 0.01f);
	ImGui::Text("Quads: %d", GLCore::Renderer::GetStats().QuadCount);
	ImGui::Text("DrawCalls: %d", GLCore::Renderer::GetStats().DrawCount);
	ImGui::End();
}

void BRLayer::OnEvent(GLCore::Event& e)
{
	//LOG_TRACE(e);
	//m_CameraController.OnEvent(e);
	m_EditorCamera.OnEvent(e);
}