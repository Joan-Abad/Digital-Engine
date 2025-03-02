#include "Graphics/EngineGraphicsAPI.h"
#include <GLFW/glfw3.h>
#include <iostream>

GraphicsAPI::GraphicsAPI()
{
    
}

bool GraphicsAPI::InitializeGraphicsFramework()
{
    if(!glfwInit())
    {
        std::cerr << "GLFW initialization failed\n";
        return false; 
    }

    return true; 

}
