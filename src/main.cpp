#include <iostream>
#include "Globals.h"
#include "Logger.h"
#include "DigitalMath/DigitalMath.h"


int main() {

    DigitalEngine = std::make_unique<class DigitalEngine>(); 

    DigitalEngine->Init();
    DigitalEngine->Tick();
    DigitalEngine->End();
    
    return 0;
}
