#include "BRLayer.h"
#include "glm/gtc/matrix_transform.hpp"

BRLayer::BRLayer() :Layer("BRLayer"),m_Zero("Textures/apple.png"),m_One("Textures/Google.png"){}
BRLayer::~BRLayer() {}

void BRLayer::OnAttach() 
{
	//glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	float vertexPositions[] =
	{ -0.6f,-0.45f,0.0f, 0.1f,0.3f,0.5f,1.0f, 0.0f,0.0f, 0.0f,
	  -0.1f,-0.45f,0.0f, 0.5f,0.4f,0.3f,1.0f, 1.0f,0.0f, 0.0f,
	  -0.1f, 0.45f,0.0f, 0.1f,0.2f,0.2f,1.0f, 1.0f,1.0f, 0.0f,
	  -0.6f, 0.45f,0.0f, 0.1f,0.1f,0.5f,1.0f, 0.0f,1.0f, 0.0f,

	  0.1f,-0.45f,0.0f, 0.5f,0.3f,0.5f,1.0f, 0.0f,0.0f, 1.0f,
	  0.6f,-0.45f,0.0f, 0.5f,0.3f,0.5f,1.0f, 1.0f,0.0f, 1.0f,
	  0.6f, 0.45f,0.0f, 0.5f,0.3f,0.5f,1.0f, 1.0f,1.0f, 1.0f,
	  0.1f, 0.45f,0.0f, 0.5f,0.3f,0.5f,1.0f, 0.0f,1.0f, 1.0f
		
	};
	m_VB = std::make_unique<VertexBuffer>(vertexPositions, 8 * 10 * sizeof(float));
	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(4);
	layout.Push<float>(2);
	layout.Push<float>(1);
	unsigned int indices[] =
	{
		0,1,2,
		2,3,0,

		4,5,6,
		6,7,4
	};
	m_VA.AddBuffer(*(m_VB.get()),layout);
	m_IB = std::make_unique<IndexBuffer>(indices, 12);
	
	m_Zero.Bind();
	m_One.Bind(1);

	m_Shader = std::make_unique<Shader>("Assets/BasicTriangle.shader");
	m_Shader->Bind();
	int sample[2] = { 0,1};
	m_Shader->SetUniform1iv("u_Textures", 2, sample);
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

	m_Shader->Bind();
    //m_Shader->SetUniform4f("u_Color", 1.0f, 1.0f, 1.0f, 1.0f);
	
	m_Renderer.Draw(m_VA, *(m_IB.get()), *(m_Shader.get()));
}

void BRLayer::ImGuiRender()
{
	ImGui::Begin("Test");
	static bool show = true;
	//ImGui::ShowDemoWindow(&show);
	ImGui::ColorEdit4("Square Alternate Color",(float*)&m_BGColor);
	ImGui::End();
}

void BRLayer::OnEvent(GLCore::Event& e)
{
	LOG_TRACE(e);
}