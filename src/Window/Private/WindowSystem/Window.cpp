#include "WindowSystem/Window.h"
#include "Globals.h"
#include <iostream>

Window::Window(const WindowParameters& WindowCreationParams)
    : WindowParams(WindowCreationParams) 
{
    InitializeWindow();
}

void Window::InitializeWindow()
{
    window = glfwCreateWindow(WindowParams.Width, WindowParams.Height, WindowParams.WindowName, nullptr, nullptr);

   if(!window)
   {
       std::cerr << "Window could not be initialized correctly\n";
       return; 
   }

    if(const std::shared_ptr<Renderer> Renderer = DigitalEngine->GetRenderer())
        Renderer->MakeContextCurrent(this);
    else
        std::cerr << "Could not find the Renderer inside Window::InitializeWindow\n";
    
}

void Window::Update()
{
    // Main loop
        Draw();
}

void Window::Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Swap buffers
    glfwSwapBuffers(window);
}

void Window::CloseWindow()
{
    // Cleanup
    glfwDestroyWindow(window);
    glfwTerminate();
}

bool Window::ShouldCloseWindow()
{
    return glfwWindowShouldClose(window);
}