#include "IIndexBuffer.h"
#include "Renderer.h"
#include "Globals.h"
#include "OpenGLIndexBuffer.h"

std::unique_ptr<IIndexBuffer> IIndexBuffer::Create(const uint32_t* indices, size_t count)
{
    switch(DigitalEngine->GetCurrentGraphicsAPI())
    {
    case Graphics_API::DirectX:
        return nullptr; //Implement
    case Graphics_API::OpenGL:
        return std::make_unique<OpenGLIndexBuffer>(indices, count);
    }
    
    return nullptr; 
}
