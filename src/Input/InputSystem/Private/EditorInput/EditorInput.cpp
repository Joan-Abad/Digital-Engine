#include "EditorInput/EditorInput.h"
#include "GLFW/glfw3.h"

EditorInput::EditorInput()
{
    
}

void EditorInput::Update()
{
    // Poll events
    glfwPollEvents();
}
