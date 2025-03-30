#include "OpenGLTexture.h"

OpenGLTexture::OpenGLTexture(const std::string& filePath)
{
}

bool OpenGLTexture::LoadFromFile(const std::string& filePath)
{
	return false;
}

bool OpenGLTexture::CreateEmpty(int width, int height, int format)
{
	return false;
}

void OpenGLTexture::Bind(unsigned int slot) const
{
}

void OpenGLTexture::Unbind() const
{
}

int OpenGLTexture::GetWidth() const
{
	return 0;
}

int OpenGLTexture::GetHeight() const
{
	return 0;
}

void OpenGLTexture::Release()
{
}
