#pragma once
#include <string>
class Texture
{
public:
	Texture(uint32_t i_Width, uint32_t i_Height);
	Texture(const std::string& i_Filepath);
	~Texture();

	void Bind(uint32_t TextureSlot=0) const;
	void Unbind() const;
	void SetData(void * data, uint32_t size);
	inline int GetWidth() { return m_Width; }
	inline int GetHeight() { return m_Height; }
	bool operator==(const Texture& i_Other)
	{
		return m_RendererID == i_Other.m_RendererID;
	}
	
private:
	uint32_t m_RendererID;
	std::string m_Filepath;
	uint8_t* m_LocalBuffer;
	int m_Width, m_Height, m_BPP;
};
