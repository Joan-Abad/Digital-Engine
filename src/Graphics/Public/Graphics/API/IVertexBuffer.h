#pragma once
#include <memory>
class IVertexBuffer {

protected:
    IVertexBuffer();
    
public:
    virtual ~IVertexBuffer() = default;

    //Function that creates a vertex buffer of the rendering API selected
    static std::unique_ptr<IVertexBuffer> Create(const void* vertices, size_t size);
    
    virtual void Bind() = 0;
    virtual void Unbind() = 0;
};