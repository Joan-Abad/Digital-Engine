#include "OpenGLGraphicsDevice.h"
#include "Graphics/API/OpenGL/OpenGLShader.h"
#include "Graphics/API/OpenGL/OpenGLVertexBuffer.h"
#include "Graphics/API/OpenGL/OpenGLIndexBuffer.h"
#include "Graphics/API/OpenGL/OpenGLTexture.h"

OpenGLGraphicsDevice::OpenGLGraphicsDevice()
{
}

std::shared_ptr<IShader> OpenGLGraphicsDevice::CreateShader(const std::string& vertexSrc, const std::string& fragmentSrc)
{
    return std::make_shared<OpenGLShader>(vertexSrc, fragmentSrc);
}

std::shared_ptr<IVertexBuffer> OpenGLGraphicsDevice::CreateVertexBuffer(const void* data, size_t size)
{
    return std::make_shared<OpenGLVertexBuffer>();
}

std::shared_ptr<IIndexBuffer> OpenGLGraphicsDevice::CreateIndexBuffer(const void* data, size_t size)
{
    return std::make_shared<OpenGLIndexBuffer>();
}

std::shared_ptr<ITexture> OpenGLGraphicsDevice::CreateTexture(const std::string& filePath)
{
    return std::make_shared<OpenGLTexture>(filePath);
}

void OpenGLGraphicsDevice::SetViewport(int width, int height)
{
}

void OpenGLGraphicsDevice::Clear(float r, float g, float b, float a)
{
}

void OpenGLGraphicsDevice::Present()
{
}
