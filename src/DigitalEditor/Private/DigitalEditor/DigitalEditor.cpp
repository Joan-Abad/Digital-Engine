#include "DigitalEditor.h"
#include "EditorInput/EditorInput.h"

DigitalEditor::DigitalEditor()
{
    WindowManagerPtr = std::make_unique<WindowManager>();
}

void DigitalEditor::Tick()
{
    WindowManagerPtr->Update(); 
}

bool DigitalEditor::StartEditor()
{
    WindowParameters window_parameters ("Digital Engine", 1920, 1080);

    EditorInputPtr = std::make_unique<EditorInput>();
    
    MainEditorWindow = WindowManagerPtr->CreateWindow(window_parameters);

    if(!MainEditorWindow)
        return false;

    return true; 
     
}
