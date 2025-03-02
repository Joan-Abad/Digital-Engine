#pragma once

class DigitalEngine
{
public:
    DigitalEngine();

    //Gets the name of the engine that is used all around the editor
    const char* GetEngineName(){ return EngineName; }

    //Called to initialize the engine
    void Init();

    //Used to update each tick the engine
    void Tick();

    //Used to clean all the engine resources
    void End();

private:
    
    //The name of the engine used by the editor
    const char* EngineName;
    
    //Keeps track if the engine is running. If false the engine will close
    bool bIsEngineRunning; 
};
