#include "IndexBuffer.h"

#include "glUtils.h"

std::shared_ptr<IndexBuffer> IndexBuffer::Create(const unsigned int* indices, unsigned int count)
{
	return std::make_shared<IndexBuffer>(indices, count);
}

IndexBuffer::IndexBuffer(const unsigned int* indices, unsigned int count):m_Count(count)
{
	ASSERT(sizeof(unsigned int) == sizeof(GLuint));
	GLCall(glGenBuffers(1, &m_RendererID));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count*sizeof(unsigned int), indices, GL_STATIC_DRAW));
}
IndexBuffer::~IndexBuffer() 
{
	GLCall(glDeleteBuffers(1, &m_RendererID));
}
void IndexBuffer::Bind() const
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
}
void IndexBuffer::Unbind() const
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}