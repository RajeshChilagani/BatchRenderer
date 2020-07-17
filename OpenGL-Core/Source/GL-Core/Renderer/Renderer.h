#pragma once
#include "IndexBuffer.h"
#include "Shader.h"
#include "VertexArray.h"
#include "Texture.h"

#include <glm/glm.hpp>

class Renderer
{
public:
	static void Init();
	static void ShutDown();
	static void BeginBatch();
	static void Endbatch();
	static void Flush();
	static void Clear(unsigned int i_Color);
	static void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader);
	static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
	static void DrawQuad(const glm::vec2& position, const glm::vec2& size, std::shared_ptr<Texture>& textureId);

	struct Stats
	{
		uint32_t DrawCount = 0;
		uint32_t QuadCount = 0;
	};

	static const Stats& GetStats();
	static void ResetStats();
private:
};

