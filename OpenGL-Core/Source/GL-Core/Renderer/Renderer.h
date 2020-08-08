#pragma once
#include "IndexBuffer.h"
#include "Shader.h"
#include "VertexArray.h"
#include "Texture.h"
#include "OrthographicCamera.h"

#include <glm/glm.hpp>

namespace GLCore
{
	class Renderer
	{
	public:
		static void Init();
		static void ShutDown();
		static void BeginBatch(const OrthographicCamera& camera);
		static void Endbatch();
		static void Flush();
		static void Clear(unsigned int i_Color);
		static void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader);
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, std::shared_ptr<Texture>& texture);
		static void DrawQuad(const glm::mat4& transform, const glm::vec4& color);
		static void DrawQuad(const glm::mat4& transform, std::shared_ptr<Texture>& texture);
		struct Stats
		{
			uint32_t DrawCount = 0;
			uint32_t QuadCount = 0;
		};

		static const Stats& GetStats();
		static void ResetStats();
	private:
		static void FlushAndReset();
	};

}


