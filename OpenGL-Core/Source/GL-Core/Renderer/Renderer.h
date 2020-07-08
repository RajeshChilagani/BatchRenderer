#pragma once
#include "IndexBuffer.h"
#include "Shader.h"
#include "VertexArray.h"

class Renderer
{
public:
	static void BeginBatch();
	static void Endbatch();
	static void Flush();
	static void Clear(unsigned int i_Color);
	static void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader);
private:
};

