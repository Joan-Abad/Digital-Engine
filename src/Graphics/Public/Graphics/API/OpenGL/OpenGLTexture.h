#pragma once 
#include "ITexture.h"

class OpenGLTexture : public ITexture
{
public:
    OpenGLTexture() = default; 
    OpenGLTexture(const std::string& filePath);

    virtual ~OpenGLTexture() = default;

    // Load texture from file
    virtual bool LoadFromFile(const std::string& filePath);

    // Create an empty texture (for render targets, etc.)
    virtual bool CreateEmpty(int width, int height, int format);

    // Bind the texture to a specific texture unit (used in shaders)
    virtual void Bind(unsigned int slot = 0) const;

    // Unbind the texture
    virtual void Unbind() const;

    // Getters
    virtual int GetWidth() const;
    virtual int GetHeight() const;

    // Free texture memory
    virtual void Release();
};