#pragma once
#include "Renderer.h"

class Window;

class OpenGLRenderer : public Renderer
{
public:
    OpenGLRenderer();

    virtual ~OpenGLRenderer(); 
    
    virtual void Init() override;

    virtual void Draw() override; 

    virtual void Close() override;

    virtual void PostInitialize() override;

    virtual void MakeContextCurrent(Window* Window) override;
};
