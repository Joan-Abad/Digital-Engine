#pragma once
#include <memory>
#include "InputKeys.h"
#include "Window.h"



class Window;

//Manages all the input for the Digital Engine Editor side
class EditorInput
{
public:
    EditorInput();

    //Called each frame
    static void Update();

    //Check if a key is pressed
    static bool IsKeyPressed(EKey Key);

    //Check if a key is released
    static bool IsKeyReleased(EKey Key); 

    //Gets the keys pressed this frame
    static void PollEvents();

    static void SetFocusedWindow(const std::shared_ptr<Window>& Window); 

private: 
    //The window that is currently focused by the player
    static std::shared_ptr<Window> FocusedWindow; 
private: 
};