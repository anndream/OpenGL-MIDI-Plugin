/*
 ==============================================================================
 
 Ross Hoyt
 Uniforms.h
 ==============================================================================
 */

#pragma once

//==============================================================================
// Class that manages the uniform values that the shaders use.
struct Uniforms
{
    Uniforms (OpenGLContext& openGLContext, OpenGLShaderProgram& shader)
    {
        projectionMatrix = createUniform (openGLContext, shader, "projectionMatrix");
        viewMatrix       = createUniform (openGLContext, shader, "viewMatrix");
        texture          = createUniform (openGLContext, shader, "demoTexture");
        lightPosition    = createUniform (openGLContext, shader, "lightPosition");
    }
    
    ScopedPointer<OpenGLShaderProgram::Uniform> projectionMatrix, viewMatrix, texture, lightPosition;
    
private:
    static OpenGLShaderProgram::Uniform* createUniform (OpenGLContext& openGLContext,
                                                        OpenGLShaderProgram& shader,
                                                        const char* uniformName)
    {
        if (openGLContext.extensions.glGetUniformLocation (shader.getProgramID(), uniformName) < 0)
            return nullptr;
        
        return new OpenGLShaderProgram::Uniform (shader, uniformName);
    }
};
