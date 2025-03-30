#pragma once

#include <cstdint>

class IIndexBuffer
{
public:
    virtual ~IIndexBuffer() = default;

    // Bind the index buffer (required before drawing)
    virtual void Bind() const = 0;

    // Unbind the index buffer
    virtual void Unbind() const = 0;

    // Get the count of indices in the buffer
    virtual uint32_t GetCount() const = 0;

protected:
    uint32_t Count = 0;
};
#pragma once
