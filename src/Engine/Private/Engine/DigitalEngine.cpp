#include <iostream>
#include "Engine/DigitalEngine.h"
#include "Graphics/Renderer.h"

DigitalEngine::DigitalEngine()
:   EngineName("Digital Engine"),
    DigitalEditorPtr(nullptr),
    CurrentGraphicsAPI(Graphics_API::OpenGL)
{
    
}

void DigitalEngine::Init()
{
    std::cout << "Starting Digital Engine\n";

    InitializeRenderer();
    InitializeEditor();
    PostInitializeRenderer();
}

void DigitalEngine::Tick()
{
    std::cout << "Start Engine Ticking" << '\n';

    while(!ShouldCloseEditor())
    {
        DigitalEditorPtr->Tick();
        PostTick();
    }
}

void DigitalEngine::PostTick()
{
    //Flush at the end of the drame for logging.
    //TODO: Not sure if we should check if there is any character to flush ot it does it automatically.  
    std::cout << std::flush; 
}

void DigitalEngine::End()
{
    DigitalEditorPtr->CloseEditor(); 
    std::cout << "Shutting down Digital Engine\n";
}

bool DigitalEngine::ShouldCloseEditor()
{
    return DigitalEditorPtr->ShouldCloseEditor(); 
}

void DigitalEngine::InitializeEditor()
{
    DigitalEditorPtr = std::make_unique<DigitalEditor>();
    DigitalEditorPtr->StartEditor();
}

void DigitalEngine::InitializeRenderer()
{
    DigitalRendererPtr = Renderer::CreateRenderer(CurrentGraphicsAPI);
    DigitalRendererPtr->Init(); 
}

void DigitalEngine::PostInitializeRenderer()
{
    DigitalRendererPtr->PostInitialize(); 
}
