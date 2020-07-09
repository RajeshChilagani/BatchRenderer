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
	std::unique_ptr<Shader> m_Shader;
	std::vector<std::shared_ptr<Texture>> m_Textures;
	glm::mat4 m_MVP;
	glm::vec4 m_BGColor = { GetNCV(216), GetNCV(251), GetNCV(241), 1.0f };
	float m_ApplePosition[2] = { 0.0f,0.0f };
	float m_GooglePosition[2] = { 0.6f,0.0f };
};
