#pragma once
#include "Renderer.h"

class OpenGLRenderer : public Renderer
{
public:
    OpenGLRenderer();

    virtual ~OpenGLRenderer(); 
    
    virtual void Init() override;

    virtual void Draw() override; 

    virtual void Close() override; 
};
