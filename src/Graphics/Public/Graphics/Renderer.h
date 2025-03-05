#pragma once

#include <memory>

class Window;

enum class Graphics_API
{
    OpenGL,
    DirectX
};

class Renderer
{
public:
    
    Renderer();

    virtual void Init() = 0;

    virtual void PostInitialize() = 0;

    virtual void Draw() = 0; 

    virtual void Close() = 0; 

    virtual void MakeContextCurrent(Window* Window) = 0; 

    static std::shared_ptr<Renderer> CreateRenderer(Graphics_API GraphicsAPI);
};