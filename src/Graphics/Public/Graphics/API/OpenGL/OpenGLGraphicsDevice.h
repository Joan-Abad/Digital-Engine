#pragma once
#include "Graphics/API/IGraphicsDevice.h"

class OpenGLGraphicsDevice : public IGraphicsDevice
{

public: 

    OpenGLGraphicsDevice();

    virtual std::shared_ptr<IShader> CreateShader(const std::string& vertexSrc, const std::string& fragmentSrc);
    virtual std::shared_ptr<IVertexBuffer> CreateVertexBuffer(const void* data, size_t size);
    virtual std::shared_ptr<IIndexBuffer> CreateIndexBuffer(const void* data, size_t size);
    virtual std::shared_ptr<ITexture> CreateTexture(const std::string& filePath);

    virtual void SetViewport(int width, int height);
    virtual void Clear(float r, float g, float b, float a);
    virtual void Present();
};