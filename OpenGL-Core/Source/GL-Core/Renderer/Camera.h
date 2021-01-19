#pragma once
#include <glm/glm.hpp>
namespace GLCore
{
	class Camera
	{
	public:
		Camera()
			:m_Projection(glm::mat4(1.0f))
		{}
		Camera(const glm::mat4& Projection)
			:m_Projection(Projection)
		{}

		const glm::mat4& GetProjection() const
		{
			return m_Projection;
		}

		void SetProjection(const glm::mat4& CustomProjection)
		{
			m_Projection = CustomProjection;
		}

		virtual ~Camera() = default;
	protected:
		glm::mat4 m_Projection;
	};
}