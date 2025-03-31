#include "IVertexBuffer.h"

class OpenGLVertexBuffer : public IVertexBuffer
{
public:
    OpenGLVertexBuffer() = default; 
    //TODO: Check if size_t is the correct type, as opengl expects long long, not size_t(aka unsigned long long)
    OpenGLVertexBuffer(size_t size, const void* data); 
    virtual ~OpenGLVertexBuffer() override;
    virtual void Bind() override;
    virtual void Unbind() override;

private:
    uint32_t RendererID;  // OpenGL buffer ID
    size_t Size;
};