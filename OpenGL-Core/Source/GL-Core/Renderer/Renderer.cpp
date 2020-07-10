#include "Renderer.h"

#include <array>

#include "GL-Core/Core/Core.h"
#include "VertexBuffer.h"
#include "glUtils.h"

struct QuadVertex
{
	glm::vec3 Position;
	glm::vec4 Color;
	glm::vec2 TexCoord;
	float TexID;
};

struct RendererData
{
	static const uint32_t MaxQuads = 1000;
	static const uint32_t MaxVertices = MaxQuads * 4;
	static const uint32_t MaxIndices = MaxQuads * 6;
	static const uint32_t MaxTextureSlots = 32; 

	std::shared_ptr<VertexArray> QuadVertexArray;
	std::shared_ptr<VertexBuffer> QuadVertexBuffer;
	std::shared_ptr<IndexBuffer> QuadIndexBuffer;
	std::shared_ptr<Texture> whiteTexture;

	uint32_t QuadIndexCount = 0;
	QuadVertex* QuadVertexBufferBase = nullptr;
	QuadVertex* QuadVertexBufferPtr = nullptr;

	std::array<std::shared_ptr<Texture>, MaxTextureSlots> TextureSlots ;
	uint32_t TextureSlotIndex = 1; // 0 = white texture

	Renderer::Stats RenderStats;

};

static RendererData s_Data;

void Renderer::Init()
{
	s_Data.QuadVertexBufferBase = new QuadVertex[s_Data.MaxVertices];

	s_Data.QuadVertexArray = VertexArray::Create();
	s_Data.QuadVertexArray->Bind();

	s_Data.QuadVertexBuffer = VertexBuffer::Create(s_Data.MaxVertices*sizeof(QuadVertex));


	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(4);
	layout.Push<float>(2);
	layout.Push<float>(1);

	s_Data.QuadVertexArray->AddVertexBuffer(s_Data.QuadVertexBuffer, layout);

	uint32_t* quadIndices= new uint32_t[s_Data.MaxIndices];
	uint32_t offset = 0;
	for (uint32_t i = 0; i < s_Data.MaxIndices - 5; i += 6)
	{
		quadIndices[i]     = offset + 0;
		quadIndices[i + 1] = offset + 1;
		quadIndices[i + 2] = offset + 2;

		quadIndices[i + 3] = offset + 2;
		quadIndices[i + 4] = offset + 3;
		quadIndices[i + 5] = offset + 0;

		offset += 4;
	}

	s_Data.QuadIndexBuffer = IndexBuffer::Create(quadIndices,s_Data.MaxIndices);

	delete[] quadIndices;

	s_Data.whiteTexture = std::make_shared<Texture>(1, 1);
	uint32_t whiteTextureData = 0xffffffff;
	s_Data.whiteTexture->SetData(&whiteTextureData, sizeof(uint32_t));

	s_Data.TextureSlots[0] = s_Data.whiteTexture;

	for (int i = 1; i < s_Data.MaxTextureSlots; ++i)
	{
		s_Data.TextureSlots[i] = 0;
	}
	
}

void Renderer::ShutDown()
{
	delete[] s_Data.QuadVertexBufferBase;
}

void Renderer::BeginBatch()
{
	s_Data.QuadVertexBufferPtr = s_Data.QuadVertexBufferBase;
	s_Data.QuadIndexCount = 0;

	s_Data.TextureSlotIndex = 1;

}


void Renderer::Endbatch()
{
	uint32_t size = (s_Data.QuadVertexBufferPtr - s_Data.QuadVertexBufferBase) * sizeof(QuadVertex);
	//uint32_t size = ((uint8_t*)s_Data.QuadVertexBufferPtr - (uint8_t*)s_Data.QuadVertexBufferBase);
	s_Data.QuadVertexBuffer->SetData(0, size, s_Data.QuadVertexBufferBase);
}

void Renderer::Flush()
{
	if (s_Data.QuadIndexCount == 0)
		return;
	for (uint32_t i = 0; i < s_Data.TextureSlotIndex; ++i)
	{
		s_Data.TextureSlots[i]->Bind(i);
	}
	GLCall(glDrawElements(GL_TRIANGLES, s_Data.QuadIndexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr));
	s_Data.RenderStats.DrawCount++;
}

void Renderer::DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color)
{
	if (s_Data.QuadIndexCount >=s_Data.MaxIndices)
	{
		Endbatch();
		Flush();
		BeginBatch();
	}


	float textureIndex = 0.0f;

	s_Data.QuadVertexBufferPtr->Position = glm::vec3(position, 0.0f);
	s_Data.QuadVertexBufferPtr->Color = color;
	s_Data.QuadVertexBufferPtr->TexCoord = { 0.0f,0.0f };
	s_Data.QuadVertexBufferPtr->TexID = textureIndex;
	s_Data.QuadVertexBufferPtr++;

	s_Data.QuadVertexBufferPtr->Position = { position.x + size.x,position.y,0.0f };
	s_Data.QuadVertexBufferPtr->Color = color;
	s_Data.QuadVertexBufferPtr->TexCoord = { 1.0f,0.0f };
	s_Data.QuadVertexBufferPtr->TexID = textureIndex;
	s_Data.QuadVertexBufferPtr++;

	s_Data.QuadVertexBufferPtr->Position = { position.x + size.x,position.y + size.y,0.0f };
	s_Data.QuadVertexBufferPtr->Color = color;
	s_Data.QuadVertexBufferPtr->TexCoord = { 1.0f,1.0f };
	s_Data.QuadVertexBufferPtr->TexID = textureIndex;
	s_Data.QuadVertexBufferPtr++;

	s_Data.QuadVertexBufferPtr->Position = { position.x,position.y + size.y,0.0f };
	s_Data.QuadVertexBufferPtr->Color = color;
	s_Data.QuadVertexBufferPtr->TexCoord = { 0.0f,1.0f };
	s_Data.QuadVertexBufferPtr->TexID = textureIndex;
	s_Data.QuadVertexBufferPtr++;

	s_Data.QuadIndexCount += 6;
	s_Data.RenderStats.QuadCount++;
}

void Renderer::DrawQuad(const glm::vec2& position, const glm::vec2& size, std::shared_ptr<Texture>& texture)
{
	if (s_Data.QuadIndexCount >= s_Data.MaxIndices || s_Data.TextureSlotIndex > 31)
	{
		Endbatch();
		Flush();
		BeginBatch();
	}

	constexpr glm::vec4 color = {1.0f,1.0f,1.0f,1.0f};

	float textureIndex = 0.0f;
	for (uint32_t i = 1; i < s_Data.TextureSlotIndex; ++i)
	{
		if (*s_Data.TextureSlots[i].get() == *texture.get())
		{
			textureIndex = static_cast<float>(i);
			break;
		}
			
	}

	if (textureIndex == 0.0f)
	{
		textureIndex = static_cast<float>(s_Data.TextureSlotIndex);
		s_Data.TextureSlots[s_Data.TextureSlotIndex] = texture;
		s_Data.TextureSlotIndex++;
	}

	s_Data.QuadVertexBufferPtr->Position = glm::vec3(position,0.0f);
	s_Data.QuadVertexBufferPtr->Color = color;
	s_Data.QuadVertexBufferPtr->TexCoord = { 0.0f,0.0f };
	s_Data.QuadVertexBufferPtr->TexID = textureIndex;
	s_Data.QuadVertexBufferPtr++;

	s_Data.QuadVertexBufferPtr->Position = {position.x+size.x,position.y,0.0f};
	s_Data.QuadVertexBufferPtr->Color = color;
	s_Data.QuadVertexBufferPtr->TexCoord = { 1.0f,0.0f };
	s_Data.QuadVertexBufferPtr->TexID = textureIndex;
	s_Data.QuadVertexBufferPtr++;

	s_Data.QuadVertexBufferPtr->Position = { position.x + size.x,position.y +size.y,0.0f };
	s_Data.QuadVertexBufferPtr->Color = color;
	s_Data.QuadVertexBufferPtr->TexCoord = { 1.0f,1.0f };
	s_Data.QuadVertexBufferPtr->TexID = textureIndex;
	s_Data.QuadVertexBufferPtr++;

	s_Data.QuadVertexBufferPtr->Position = { position.x,position.y+size.y,0.0f };
	s_Data.QuadVertexBufferPtr->Color = color;
	s_Data.QuadVertexBufferPtr->TexCoord = { 0.0f,1.0f };
	s_Data.QuadVertexBufferPtr->TexID = textureIndex;
	s_Data.QuadVertexBufferPtr++;

	s_Data.QuadIndexCount += 6;
	s_Data.RenderStats.QuadCount++;
}

const Renderer::Stats& Renderer::GetStats()
{
	return s_Data.RenderStats;
}

void Renderer::ResetStats()
{
	s_Data.RenderStats.DrawCount = 0;
	s_Data.RenderStats.QuadCount = 0;
}

void Renderer::Clear(unsigned int i_Color) 
{
	GLCall(glClear(i_Color));
}
void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) 
{
	va.Bind();
	ib.Bind();
	shader.Bind();
	GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}