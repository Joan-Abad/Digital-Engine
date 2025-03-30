#pragma once

class IVertexBuffer {
public:
    virtual ~IVertexBuffer() = default;
    virtual void Bind() = 0;
    virtual void Unbind() = 0;
};