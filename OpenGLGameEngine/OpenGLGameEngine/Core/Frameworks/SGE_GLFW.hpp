//
//  SGE_GLFW.hpp
//  OpenGLGameEngine
//
//  Created by Sonar Systems on 18/09/2016.
//  Copyright © 2016 Sonar Systems. All rights reserved.
//

#pragma once

#include "DEFINITIONS.h"

#ifdef SGE__GLFW

#include "FrameworkInterface.h"

#include <GLFW/glfw3.h>

namespace SonarGameEngine
{
    class SGE_GLFW: public FrameworkInterface
    {
    public:
        SGE_GLFW( );
        
        void Init( ) override;
                
        bool PollEvents( ) override;
        
        void SwapBuffers( ) override;
        
        void CleanUp( ) override;
        
    private:
        GLFWwindow *window;
    };
}
#endif
