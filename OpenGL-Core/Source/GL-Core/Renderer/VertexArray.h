#pragma once
#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
class VertexArray
{
public:
	static std::shared_ptr<VertexArray> Create();
	VertexArray();
	~VertexArray();
	void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
	void AddIndexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer, const VertexBufferLayout& layout);
	void Bind() const;
	void Unbind() const;
private:
	unsigned int m_RendererId;
	//std::shared_ptr<IndexBuffer> m_IndexBuffer;
	VertexBufferLayout m_Layout;

};