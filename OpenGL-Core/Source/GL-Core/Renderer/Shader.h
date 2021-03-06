#pragma once
#include <string>
#include <unordered_map>

#include <glm/glm.hpp>
struct ShaderProgramSource
{
	std::string VertexShader;
	std::string FragmentShader;
};
enum class ShaderType
{
	NONE = -1, VERTEX = 0, FRAGMENT = 1
};

class Shader
{
public:
	Shader(const std::string& i_Filepath);
	~Shader();
	void Bind() const;
	void Unbind() const;
	void SetUniform1i(const std::string& i_Name, int v);
	void SetUniform1f(const std::string& i_Name, float v);
	void SetUniform4f(const std::string& i_Name, float v1, float v2, float v3, float v4);
	void SetUniformMat4f(const std::string& i_Name, const glm::mat4& matrix);
	void SetUniform1iv(const std::string& i_Name, int count, int* value);

	unsigned int GetId() { return m_RendererID; }
private:
	ShaderProgramSource ParseShader(const std::string& i_FilePath);
	unsigned int CreateShader(const std::string i_VertexShader, const std::string i_FragmentShader);
	unsigned int CompileShader(unsigned int i_ShaderType, std::string i_ShaderSource);
	int GetUniformLocation(const std::string& i_Name);
	std::string m_FilePath;
	unsigned int m_RendererID;
	std::unordered_map<std::string, int> m_UniformLocationCache;

};