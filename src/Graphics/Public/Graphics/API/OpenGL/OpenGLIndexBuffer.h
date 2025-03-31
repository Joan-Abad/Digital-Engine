#pragma once
#include "IIndexBuffer.h"

class OpenGLIndexBuffer : public IIndexBuffer 
{
public:
    OpenGLIndexBuffer() = default;
    //TODO: check if it is ok to pass size_t or should be long long instead as OpenGL uses it. 
    OpenGLIndexBuffer(const uint32_t* indices, size_t count);
    
    virtual ~OpenGLIndexBuffer() override;

    // Bind the index buffer (required before drawing)
    virtual void Bind() const override;

    // Unbind the index buffer
    virtual void Unbind() const override;

    // Get the count of indices in the buffer
    virtual long long GetCount() const override { return Count; }

protected:
    long long Count = 0;
    uint32_t RendererID;
};
