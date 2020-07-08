#include "Renderer.h"

#include "glUtils.h"

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