#include "DigitalEditor.h"
#include "EditorInput/EditorInput.h"

DigitalEditor::DigitalEditor()
{
    WindowManagerPtr = std::make_unique<WindowManager>();
    EditorInputPtr = std::make_unique<EditorInput>();
    
}

void DigitalEditor::Tick()
{
    EditorInputPtr->Update(); 
    WindowManagerPtr->Update(); 
}

bool DigitalEditor::StartEditor()
{
    WindowParameters window_parameters ("Digital Engine", 1920, 1080);
    
    MainEditorWindow = WindowManagerPtr->CreateWindow(window_parameters);

    EditorInput::SetFocusedWindow(MainEditorWindow); 

    if(!MainEditorWindow)
        return false;

    return true; 
     
}
