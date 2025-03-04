#include <iostream>
#include "Engine/DigitalEngine.h"
#include "Graphics/EngineGraphicsAPI.h"

DigitalEngine::DigitalEngine()
:   EngineName("Digital Engine"),
    bIsEngineRunning(false),
    DigitalEditorPtr(nullptr)
{
    
}

void DigitalEngine::Init()
{
    std::cout << "Starting Digital Engine\n";
    
    if(!GraphicsAPI::InitializeGraphicsFramework())
        return;

    DigitalEditorPtr = std::make_unique<DigitalEditor>();

    DigitalEditorPtr->StartEditor(); 
        
    bIsEngineRunning = true;    
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

void DigitalEngine::InitEditor()
{
    DigitalEditorPtr = std::make_unique<DigitalEditor>();

    DigitalEditorPtr->StartEditor();
}
