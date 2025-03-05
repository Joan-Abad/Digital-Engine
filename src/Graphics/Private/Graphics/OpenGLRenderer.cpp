#include "OpenGLRenderer.h"

#include <iostream>

#include "GLFW/glfw3.h"

OpenGLRenderer::OpenGLRenderer()
{
    
}

OpenGLRenderer::~OpenGLRenderer()
{
    
}

void OpenGLRenderer::Init()
{
    if(!glfwInit())
    {
        std::cerr << "GLFW initialization failed\n";
        exit(EXIT_FAILURE); 
    }
}

void OpenGLRenderer::Draw()
{
}

void OpenGLRenderer::Close()
{
}
