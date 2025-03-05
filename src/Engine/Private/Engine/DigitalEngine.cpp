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

    InitializeEditor();
}

void DigitalEngine::Tick()
{ 
    while(!ShouldCloseEditor())
    {
        std::cout << "Engine Ticking\n";
        DigitalEditorPtr->Tick(); 
    }
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

    InitializeRenderer();
    
    DigitalEditorPtr = std::make_unique<DigitalEditor>();
    DigitalEditorPtr->StartEditor();
}

void DigitalEngine::InitializeRenderer()
{
    DigitalRendererPtr = Renderer::CreateRenderer(CurrentGraphicsAPI);
    DigitalRendererPtr->Init(); 
}
