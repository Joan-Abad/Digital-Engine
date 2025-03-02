#pragma once
#include <memory>
#include <vector>
#include "Window.h"

class WindowManager
{
    friend class Window; 

public:
    WindowManager();

    //Each tick execution
    void Update();
    
    //Call to create a window
    std::shared_ptr<Window> CreateWindow(WindowParameters& WindowCreationParams);

private:
    //All the windows of the application
     std::vector<std::shared_ptr<Window>> windows; 
};
