#pragma once
#include "GLFW/glfw3.h"

struct WindowParameters
{
    WindowParameters(const char* WindowName, int Width, int Height)
    {
        this->WindowName = WindowName;
        this->Width = Width;
        this->Height = Height; 
    }

    //The name that will be displayed up the window
    const char* WindowName;

    //Width of the window
    int Width;

    //Height of the window
    int Height; 
};

class Window
{
public:
    
    Window(const WindowParameters& WindowCreationParams);

    virtual void InitializeWindow();

    virtual void Update();

    virtual void Draw();

    virtual void CloseWindow();

    virtual bool ShouldCloseWindow();

    //Gets the API window, in this case glfw
    GLFWwindow* GetWindow() const { return window; }
    
private:
    WindowParameters WindowParams;

    GLFWwindow* window; 
};