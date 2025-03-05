#include "..\..\Public\Graphics\Renderer.h"
#include <GLFW/glfw3.h>
#include <iostream>

#include "DirectXRenderer.h"
#include "OpenGLRenderer.h"

Renderer::Renderer()
{
    
}

std::shared_ptr<Renderer> Renderer::CreateRenderer(Graphics_API GraphicsAPI)
{
    switch(GraphicsAPI)
    {
    case Graphics_API::OpenGL:
        return std::make_shared<OpenGLRenderer>();
    case Graphics_API::DirectX:
        return std::make_shared<DirectXRenderer>();
    }
}