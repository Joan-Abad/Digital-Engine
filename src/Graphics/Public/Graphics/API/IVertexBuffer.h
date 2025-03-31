#pragma once
#include <memory>
class IVertexBuffer {

protected:
    IVertexBuffer();
    
public:
    virtual ~IVertexBuffer() = default;

    //Function that creates a vertex buffer of the rendering API selected
    static std::unique_ptr<IVertexBuffer> Create(size_t size, const void* data);
    
    virtual void Bind() = 0;
    virtual void Unbind() = 0;
};