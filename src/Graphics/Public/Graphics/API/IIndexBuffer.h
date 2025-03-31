#pragma once
#include <memory>
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
    virtual long long GetCount() const = 0;

    static std::unique_ptr<IIndexBuffer> Create(const uint32_t* indices, size_t count);
protected:
    uint32_t Count = 0;
};
