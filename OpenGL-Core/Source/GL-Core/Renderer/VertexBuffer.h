#pragma once
#include "GL-Core/Core/Core.h"
class VertexBuffer
{
public:
	static std::shared_ptr<VertexBuffer> Create(unsigned int size);
	VertexBuffer(const void* Data, unsigned int size);
	VertexBuffer(unsigned int size);
	~VertexBuffer();
	void SetData(unsigned int Offset, unsigned int Size, const void* Data);
	void Bind() const;
	void Unbind() const;
private:
	unsigned int m_RendererID;
	
};

