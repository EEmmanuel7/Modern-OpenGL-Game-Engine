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
        SDL_Init( SDL_INIT_EVERYTHING );
        
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3 );
        SDL_GL_SetAttribute( SDL_GL_STENCIL_SIZE, 8 );
        SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 24 );
        
        this->window = SDL_CreateWindow( "SDL", 0, 0, coreSettings->GetScreenWidth( ), coreSettings->GetScreenHeight( ), SDL_WINDOW_OPENGL );
        
        
        SDL_DisplayMode dm;
        
        if (SDL_GetWindowDisplayMode(window, &dm) != 0)
        {
            SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
        }
        
        int w, h;
        w = dm.w;
        h = dm.h;
        
        std::cout << h << std::endl;
        
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
