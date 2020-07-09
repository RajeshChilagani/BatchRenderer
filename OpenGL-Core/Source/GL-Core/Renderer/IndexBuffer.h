#pragma once
#include "GL-Core/Core/Core.h"
class IndexBuffer
{
public:
	static std::shared_ptr<IndexBuffer> Create(const unsigned int* indices, unsigned int count);
	IndexBuffer(const unsigned int* indices, unsigned int count);
	~IndexBuffer();
	void Bind() const;
	void Unbind() const;
	inline unsigned int GetCount() const { return m_Count; }
private:
	unsigned int m_RendererID;
	unsigned int m_Count;
};

