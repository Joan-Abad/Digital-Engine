#include "WindowSystem/Window.h"
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
        std::cerr << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        return;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    
}

void Window::Update()
{
    // Main loop
    while (!ShouldCloseWindow()) {

        UpdateInput();

        Draw();        
    }

    CloseWindow();
}

void Window::UpdateInput()
{
    // Poll events
    glfwPollEvents();
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
