#include "OpenGLRenderer.h"
#include <iostream>

#include "glad.h"
#include "Window.h"
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
        //TODO: Change this exit method
        exit(EXIT_FAILURE); 
    }

    
}

void OpenGLRenderer::Draw()
{
    std::cout << "Open GL renderer drawer ticking\n"; 
}

void OpenGLRenderer::Close()
{
}

void OpenGLRenderer::PostInitialize()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD\n";
        //TODO: Change this exit method
        exit(EXIT_FAILURE);
    }
}

void OpenGLRenderer::MakeContextCurrent(Window* Window)
{
    glfwMakeContextCurrent(Window->GetWindow());
}
