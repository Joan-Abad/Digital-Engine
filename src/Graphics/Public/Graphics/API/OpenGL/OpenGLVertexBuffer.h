#include "IVertexBuffer.h"

class OpenGLVertexBuffer : public IVertexBuffer
{
public:
    OpenGLVertexBuffer() = default; 
    virtual ~OpenGLVertexBuffer() = default;
    virtual void Bind();
    virtual void Unbind();
};