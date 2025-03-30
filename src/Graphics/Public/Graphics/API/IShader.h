#pragma once
#include <string>

class IShader {
public:
    virtual ~IShader() = default;
    virtual void Bind() = 0;
    virtual void Unbind() = 0;
};