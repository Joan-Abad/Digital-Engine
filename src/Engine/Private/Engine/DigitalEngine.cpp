#include "Engine/DigitalEngine.h"
#include "Graphics/EngineGraphicsAPI.h"
#include <iostream>

DigitalEngine::DigitalEngine()
:   EngineName("Digital Engine"),
    bIsEngineRunning(false)
{
    
}

void DigitalEngine::Init()
{
    std::cout << "Starting Digital Engine\n";

    GraphicsAPI::InitializeGraphicsFramework();
    
    bIsEngineRunning = true; 
}

void DigitalEngine::Tick()
{
    while(bIsEngineRunning)
    {
        std::cout << "Engine Ticking\n";
    }
}

void DigitalEngine::End()
{
    std::cout << "Shutting down Digital Engine\n";
}
