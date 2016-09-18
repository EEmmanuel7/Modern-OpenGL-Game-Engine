//
//  SGE_SFML.hpp
//  OpenGLGameEngine
//
//  Created by Sonar Systems on 18/09/2016.
//  Copyright © 2016 Sonar Systems. All rights reserved.
//

#pragma once

#include "FrameworkInterface.h"

#include <SFML/window.hpp>

namespace SonarGameEngine
{
    class SGE_SFML: public FrameworkInterface
    {
    public:
        SGE_SFML( );
        
        void Init( );
                
        bool PollEvents( );
        
        void SwapBuffers( );
        
        void CleanUp( );
        
    private:
        sf::Window *window;
    };
}
