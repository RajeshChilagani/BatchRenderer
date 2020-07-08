#pragma once
#include "GLCore.h"
#include "GL-Core/Renderer/Texture.h"
#include "GL-Core/Renderer/Utils.h"

class BRLayer : public GLCore::Layer
{
public:
	BRLayer();
	virtual ~BRLayer();

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnUpdate() override;
	virtual void ImGuiRender() override;
	virtual void OnEvent(GLCore::Event& e) override;
private:
	VertexArray m_VA;
	std::unique_ptr<VertexBuffer> m_VB;
	std::unique_ptr<IndexBuffer> m_IB;
	std::unique_ptr<Shader> m_Shader;
	Renderer m_Renderer;
	glm::mat4 m_MVP;
	Texture m_Zero, m_One;
	glm::vec4 m_BGColor = { GetNCV(216), GetNCV(251), GetNCV(241), 1.0f };
	float m_ApplePosition[2] = { -0.6f,0.0f };
	float m_GooglePosition[2] = { 0.6f,0.0f };
};
