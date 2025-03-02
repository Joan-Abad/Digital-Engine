#include <iostream>
//#include <memory>
#include "Engine/DigitalEngine.h"

int main() {

   std::unique_ptr<DigitalEngine> DigitalEngine = std::make_unique<class DigitalEngine>();

    //Engine Loop
    DigitalEngine->Init();
    DigitalEngine->Tick();
    DigitalEngine->End();
    
    return 0;
}
