#include <iostream>
#include "Globals.h"

int main() {

    DigitalEngine = std::make_unique<class DigitalEngine>(); 
    
    //Engine Loop
    DigitalEngine->Init();
    DigitalEngine->Tick();
    DigitalEngine->End();
    
    return 0;
}
