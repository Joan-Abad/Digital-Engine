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
    while(bIsEngineRunning)
    {
        std::cout << "Engine Ticking\n";
        DigitalEditorPtr->Tick(); 
    }
}

void DigitalEngine::End()
{
    std::cout << "Shutting down Digital Engine\n";
}

void DigitalEngine::InitEditor()
{
    DigitalEditorPtr = std::make_unique<DigitalEditor>();

    DigitalEditorPtr->StartEditor();
}
