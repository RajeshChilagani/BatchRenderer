#include "OrthographicCamera.h"

#include <glm/gtc/matrix_transform.hpp>
namespace GLCore
{
	OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top, float near, float far)
		:m_Projection(glm::ortho(left,right,bottom,top,near,far)),m_View(1.0f)
	{
		m_ProjectionView = m_Projection * m_View;
	}

	void OrthographicCamera::SetProjection(float left, float right, float bottom, float top, float near, float far)
	{
		m_Projection = glm::ortho(left, right, bottom, top, near, far);
		m_ProjectionView = m_Projection * m_View;
	}

	void OrthographicCamera::RecalculateViewMatrix()
	{
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_Position) * glm::rotate(glm::mat4(1.0f), glm::radians(m_ZRotation), glm::vec3(0, 0, 1));
		m_View = glm::inverse(transform);

		m_ProjectionView = m_Projection * m_View;
	}
}