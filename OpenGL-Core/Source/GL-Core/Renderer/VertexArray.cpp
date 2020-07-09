#include "VertexArray.h"

#include "glUtils.h"

std::shared_ptr<VertexArray> VertexArray::Create()
{
	return std::make_shared<VertexArray>();
}

VertexArray::VertexArray()
{
	GLCall(glGenVertexArrays(1, &m_RendererId));

}

VertexArray::~VertexArray()
{
	GLCall(glDeleteVertexArrays(1,&m_RendererId));
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
	Bind();
	vb.Bind();
	std::vector<VertexBufferLayoutElement> elements = layout.GetElements();
	unsigned int Offset = 0;
	for (unsigned int i = 0; i < elements.size(); ++i)
	{
		auto& element = elements[i];
		GLCall(glEnableVertexAttribArray(i));
		GLCall(glVertexAttribPointer(i,element.count, element.type, element.nomralized, layout.GetStride(), reinterpret_cast<const void*>(Offset)));
		Offset += element.count * VertexBufferLayoutElement::GetSizeOfType(element.type);
		
	}
	
	
}

void VertexArray::AddIndexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer, const VertexBufferLayout& layout)
{
	Bind();
	vertexBuffer->Bind();
	std::vector<VertexBufferLayoutElement> elements = layout.GetElements();
	unsigned int Offset = 0;
	for (unsigned int i = 0; i < elements.size(); ++i)
	{
		auto& element = elements[i];
		GLCall(glEnableVertexAttribArray(i));
		GLCall(glVertexAttribPointer(i, element.count, element.type, element.nomralized, layout.GetStride(), reinterpret_cast<const void*>(Offset)));
		Offset += element.count * VertexBufferLayoutElement::GetSizeOfType(element.type);

	}
}

void VertexArray::Bind() const
{
	GLCall(glBindVertexArray(m_RendererId));
}
void VertexArray::Unbind() const
{
	GLCall(glBindVertexArray(0));
}