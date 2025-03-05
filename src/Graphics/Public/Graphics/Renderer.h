#pragma once

#include <memory>

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

    virtual void Draw() = 0; 

    virtual void Close() = 0;

    static std::shared_ptr<Renderer> CreateRenderer(Graphics_API GraphicsAPI);
};