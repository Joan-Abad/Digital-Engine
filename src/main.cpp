#include <iostream>
#include "Globals.h"
#include "Logger.h"
#include "DigitalMath/DigitalMath.h"


int main() {

    DigitalEngine = std::make_unique<class DigitalEngine>(); 

    Vector2 vec(10, 20); 
    std::cout << "Vec2: " << vec << std::endl;

    DigitalEngine->Init();
    DigitalEngine->Tick();
    DigitalEngine->End();
    
    return 0;
}
