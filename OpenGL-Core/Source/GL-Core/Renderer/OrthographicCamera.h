#pragma once
#include<glm/glm.hpp>
namespace GLCore
{
	class OrthographicCamera
	{
	public:
		OrthographicCamera(float left, float right, float bottom, float top,float near=-1.0f,float far=1.0f);
		~OrthographicCamera() = default;

		void SetProjection(float left, float right, float bottom, float top, float near=-1.0f, float far=1.0f);

		inline glm::vec3 GetPosition() const { return m_Position; }
		inline void SetPositon(glm::vec3 i_Position) { m_Position = i_Position; RecalculateViewMatrix(); }

		inline float GetRotation() const { return m_ZRotation; }
		inline void SetRotation(float i_Rotation) { m_ZRotation = i_Rotation; RecalculateViewMatrix();}

		const glm::mat4& GetProjectionMatrix() const { return m_Projection; }
		const glm::mat4& GetViewMatrix() const { return m_View; }
		const glm::mat4& GetViewProjectionMatrix() const { return m_ProjectionView; }
	private:
		void RecalculateViewMatrix();
		glm::mat4 m_Projection;
		glm::mat4 m_View;
		glm::mat4 m_ProjectionView;

		glm::vec3 m_Position{0.0f,0.0f,0.0f};
		float     m_ZRotation=0.0f;
	};
}
