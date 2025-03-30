#pragma once
#include <memory>
#include "ITexture.h"
#include "IVertexBuffer.h"
#include "IShader.h"
#include "IIndexBuffer.h"

class IGraphicsDevice {
public:
    virtual ~IGraphicsDevice() = default;

    virtual std::shared_ptr<IShader> CreateShader(const std::string& vertexSrc, const std::string& fragmentSrc) = 0;
    virtual std::shared_ptr<IVertexBuffer> CreateVertexBuffer(const void* data, size_t size) = 0;
    virtual std::shared_ptr<IIndexBuffer> CreateIndexBuffer(const void* data, size_t size) = 0;
    virtual std::shared_ptr<ITexture> CreateTexture(const std::string& filePath) = 0;

    virtual void SetViewport(int width, int height) = 0;
    virtual void Clear(float r, float g, float b, float a) = 0;
    virtual void Present() = 0;
};