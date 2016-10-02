//
//  SGE_SDL.cpp
//  OpenGLGameEngine
//
//  Created by Sonar Systems on 18/09/2016.
//  Copyright © 2016 Sonar Systems. All rights reserved.
//

#include "SGE_SDL.hpp"

#ifdef SGE__SDL

#include <iostream>

namespace SonarGameEngine
{
    SGE_SDL::SGE_SDL( )
    {
        
    }
    
    void SGE_SDL::Init( )
    {
        int windowResizable(0);
        
        if ( coreSettings->GetWindowResizable( ) )
        {
            windowResizable = SDL_WINDOW_RESIZABLE;
        }
        
        int multiSampleBuffer(0);
        
        if ( coreSettings->GetAntiAliasing( ) > 0 )
        {
            multiSampleBuffer = 1;
        }
        
        SDL_Init( SDL_INIT_EVERYTHING );
        
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );
        SDL_GL_SetAttribute( SDL_GL_STENCIL_SIZE, coreSettings->GetStencilSize( ) );
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, coreSettings->GetOpenGLVersion( ).major );
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, coreSettings->GetOpenGLVersion( ).minor );
        SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, coreSettings->GetDepthSize( ) );
        SDL_GL_SetAttribute( SDL_GL_MULTISAMPLEBUFFERS, multiSampleBuffer );
        SDL_GL_SetAttribute( SDL_GL_MULTISAMPLESAMPLES, coreSettings->GetAntiAliasing( ) );
        
        this->window = SDL_CreateWindow( "SDL", 0, 0, coreSettings->GetWindowWidth( ), coreSettings->GetWindowHeight( ), SDL_WINDOW_OPENGL | windowResizable );
        
        int actualWidth, actualHeight;
        
        SDL_GL_GetDrawableSize( window, &actualWidth, &actualHeight );
        
        coreSettings->SetScaledWindowWidth( actualWidth );
        coreSettings->SetScaledWindowHeight( actualHeight );
        
        this->context = SDL_GL_CreateContext( this->window );
    }
    
    bool SGE_SDL::PollEvents( )
    {
        if ( SDL_PollEvent( &this->windowEvent ) )
        {
            if ( this->windowEvent.type == SDL_QUIT )
            {
                return false;
            }
        }
        
        return true;
    }
    
    void SGE_SDL::SwapBuffers( )
    {
        SDL_GL_SwapWindow( this->window );
    }
    
    void SGE_SDL::CleanUp( )
    {
        SDL_GL_DeleteContext( this->context );
        SDL_DestroyWindow( this->window );
        SDL_Quit( );
    }
}

#endif
