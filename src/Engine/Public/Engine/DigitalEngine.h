#pragma once
#include <memory>

#include "Renderer.h"
#include "DigitalEditor/DigitalEditor.h"
#include "EditorInput/EditorInput.h"


class Renderer;

class DigitalEngine
{
public:
    DigitalEngine();

    //Gets the name of the engine that is used all around the editor
    const char* GetEngineName() const { return EngineName; }

    //Called to initialize the engine
    void Init();

    //Used to update each tick the engine
    void Tick();

    //Used to clean all the engine resources
    void End();

    //Manages how the engine and editor is closed
    bool ShouldCloseEditor();

    
    const std::shared_ptr<Renderer>& GetRenderer() const { return DigitalRendererPtr; }

private:

    //Initialize all the engine editor
    void InitializeEditor();

    //Initialize the renderer in the correct API
    void InitializeRenderer();

    //Post initialize renderer in the correct API
    void PostInitializeRenderer();
    
    //The name of the engine used by the editor
    const char* EngineName;

    //Manages the editor
    std::unique_ptr<DigitalEditor> DigitalEditorPtr;

    //Manages the rending part of the editor
    std::shared_ptr<Renderer> DigitalRendererPtr;

    //The Grraphics API the engine is using to render everything
    Graphics_API CurrentGraphicsAPI; 
};
