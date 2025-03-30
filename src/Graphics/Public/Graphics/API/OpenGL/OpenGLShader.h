#pragma once
#include "IShader.h"

class OpenGLShader : public IShader
{
public:
    OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
    virtual ~OpenGLShader() = default;
    virtual void Bind();
    virtual void Unbind();
};