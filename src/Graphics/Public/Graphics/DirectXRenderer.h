#pragma once
#include "Renderer.h"

class DirectXRenderer : public Renderer
{
public:
    DirectXRenderer();

    virtual ~DirectXRenderer(); 
    
    virtual void Init() override;

    virtual void PostInitialize() override;
    
    virtual void Draw() override; 

    virtual void Close() override;

    virtual void MakeContextCurrent(Window* Window) override; 

};
