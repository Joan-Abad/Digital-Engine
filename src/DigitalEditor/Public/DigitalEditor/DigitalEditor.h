#pragma once
#include <memory>
#include "WindowManager.h"

class EditorInput;

class DigitalEditor
{
public:
    DigitalEditor();

    //Called each frame
    void Tick();
    
    //Start all the editor part of the engine
    bool StartEditor();

    //If true, will indicate the engine to close editor
    bool ShouldCloseEditor();

    //Closes Digital Editor
    void CloseEditor();

private:

    //The main editor of the window
    std::shared_ptr<Window> MainEditorWindow; 
    
    //Manages all the creation of the editor windows
    std::unique_ptr<WindowManager> WindowManagerPtr;

    std::unique_ptr<EditorInput> EditorInputPtr; 

};
