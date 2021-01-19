#pragma once
#include "GLCore.h"
#include "GL-Core/Renderer/Texture.h"
#include "GL-Core/Renderer/Utils.h"
#include "GL-Core/Renderer/OrthographicCameraController.h"
#include "GL-Core/Core/Timestep.h"
#include "GL-Core/Renderer/EditorCamera.h"



class BRLayer : public GLCore::Layer
{
public:
	BRLayer();
	virtual ~BRLayer();

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnUpdate(GLCore::Timestep dt) override;
	virtual void ImGuiRender() override;
	virtual void OnEvent(GLCore::Event& e) override;
private:
	std::unique_ptr<Shader> m_Shader;
	std::vector<std::shared_ptr<Texture>> m_Textures;
	glm::vec4 m_BGColor = { GetNCV(15), GetNCV(15), GetNCV(25), 1.0f };
	float m_BatchPosition[2] = { 10.0f,0.0f };
	float m_SquarePosition[2] = { 0.0f,0.0f };
	GLCore::OrthographicCameraController m_CameraController;
	GLCore::EditorCamera m_EditorCamera;
};
