#include "GL-Core/Core/Application.h"
#include "GL-Core/Core/Input.h"

#include <GLFW/glfw3.h>
namespace GLCore
{
	bool Input::IsKeyPressed(Key i_KeyCode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, static_cast<int>(i_KeyCode));
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool Input::IsMouseButtonPressed(Mouse i_MouseButton)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, static_cast<int>(i_MouseButton));
		return state == GLFW_PRESS;
	}

	std::pair<float, float> Input::GetMousePosition()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);
		return { static_cast<float>(xPos),static_cast<float>(yPos)};
	}

	float Input::GetMousePositionX()
	{
		auto [x, y] = GetMousePosition();
		return x;
	}

	float Input::GetMousePositionY()
	{
		auto [x, y] = GetMousePosition();
		return y;
	}
}