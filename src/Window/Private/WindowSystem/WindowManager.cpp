#include "WindowManager.h"

#include "Window.h"

WindowManager::WindowManager()
{
    
}

void WindowManager::Update()
{
    for(auto window : windows)
    {
        window->Update();
    }
}


std::shared_ptr<Window> WindowManager::CreateWindow(WindowParameters& WindowCreationParams)
{
    std::shared_ptr<Window> window = std::make_shared<Window>(WindowCreationParams);
    windows.push_back(window);
    return window; 
}
