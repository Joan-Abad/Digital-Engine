#include "EditorInput/EditorInput.h"
#include <iostream>
#include "GLFW/glfw3.h"


std::shared_ptr<Window> EditorInput::FocusedWindow = nullptr; 

EditorInput::EditorInput()
{
    
}

void EditorInput::Update()
{
    PollEvents();

    if(IsKeyPressed(EKey::A))
    {
        std::cout << "KEY A PRESSED\n"; 
    }
    else if(IsKeyReleased(EKey::A))
    {
        std::cout << "KEY A Released\n";
    }
}

bool EditorInput::IsKeyPressed(EKey Key)
{
    return glfwGetKey(FocusedWindow->GetWindow(), static_cast<int>(Key)) == static_cast<int>(EKeyState::KEY_Pressed);        
}

bool EditorInput::IsKeyReleased(EKey Key)
{
    return glfwGetKey(FocusedWindow->GetWindow(), static_cast<int>(Key)) == static_cast<int>(EKeyState::Key_Released);        
}

void EditorInput::PollEvents()
{
    glfwPollEvents();
}

void EditorInput::SetFocusedWindow(const std::shared_ptr<Window>& Window)
{
    FocusedWindow = Window; 
}
