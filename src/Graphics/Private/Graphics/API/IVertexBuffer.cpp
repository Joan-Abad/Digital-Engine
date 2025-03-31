#include "IVertexBuffer.h"
#include "Renderer.h"
#include "Globals.h"
#include "OpenGLVertexBuffer.h"

IVertexBuffer::IVertexBuffer()
{
    
}

std::unique_ptr<IVertexBuffer> IVertexBuffer::Create(const void* vertices, size_t size)
{
    switch(DigitalEngine->GetCurrentGraphicsAPI())
    {
    case Graphics_API::DirectX:
        return nullptr; //Implement
    case Graphics_API::OpenGL:
        return std::make_unique<OpenGLVertexBuffer>(vertices, size);
    }
    
    return nullptr; 
}
