#pragma once
#include <string>

class ITexture {
public:
    virtual ~ITexture() = default;

    // Load texture from file
    virtual bool LoadFromFile(const std::string& filePath) = 0;

    // Create an empty texture (for render targets, etc.)
    virtual bool CreateEmpty(int width, int height, int format) = 0;

    // Bind the texture to a specific texture unit (used in shaders)
    virtual void Bind(unsigned int slot = 0) const = 0;

    // Unbind the texture
    virtual void Unbind() const = 0;

    // Getters
    virtual int GetWidth() const = 0;
    virtual int GetHeight() const = 0;

    // Free texture memory
    virtual void Release() = 0;
};