#pragma once
#include <memory>
#include "WindowManager.h"

class DigitalEditor
{
public:
    DigitalEditor();

    //Called each frame
    void Tick();
    
    //Start all the editor part of the engine
    bool StartEditor();

    

private:

    //The main editor of the window
    std::shared_ptr<Window> MainEditorWindow; 
    
    //Manages all the creation of the editor windows
    std::unique_ptr<WindowManager> WindowManagerPtr; 
};
