#include "IVertexBuffer.h"
#include "Renderer.h"
#include "Globals.h"
#include "OpenGLVertexBuffer.h"

IVertexBuffer::IVertexBuffer()
{
    
}

std::unique_ptr<IVertexBuffer> IVertexBuffer::Create(size_t size, const void* data)
{
    switch(DigitalEngine->GetCurrentGraphicsAPI())
    {
    case Graphics_API::DirectX:
        return nullptr; //Implement
    case Graphics_API::OpenGL:
        return std::make_unique<OpenGLVertexBuffer>(size, data);
    }
    
    return nullptr; 
}
