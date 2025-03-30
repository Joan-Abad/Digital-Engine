#pragma once
#include "IIndexBuffer.h"

class OpenGLIndexBuffer : public IIndexBuffer 
{
public:
    virtual ~OpenGLIndexBuffer() = default;

    // Bind the index buffer (required before drawing)
    virtual void Bind() const;

    // Unbind the index buffer
    virtual void Unbind() const;

    // Get the count of indices in the buffer
    virtual uint32_t GetCount() const;

protected:
    uint32_t Count = 0;
};
