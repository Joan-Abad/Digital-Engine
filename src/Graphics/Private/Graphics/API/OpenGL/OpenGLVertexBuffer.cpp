#include "OpenGLVertexBuffer.h"
#include <glad.h>

OpenGLVertexBuffer::OpenGLVertexBuffer(size_t size, const void* data) : Size(size)   
{
    glGenBuffers(1, &RendererID);
    glBindBuffer(GL_ARRAY_BUFFER, RendererID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

OpenGLVertexBuffer::~OpenGLVertexBuffer()
{
    glDeleteBuffers(1, &RendererID);
}

void OpenGLVertexBuffer::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, RendererID);
}

void OpenGLVertexBuffer::Unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
