//
//  CoreSettings.cpp
//  OpenGLGameEngine
//
//  Created by Sonar Systems on 25/09/2016.
//  Copyright © 2016 Sonar Systems. All rights reserved.
//

#include "CoreSettings.hpp"

#define SGE_DEF_SCREEN_WIDTH 640
#define SGE_DEF_SCREEN_HEIGHT 480

namespace SonarGameEngine
{
    CoreSettings *CoreSettings::sInstance = 0;
 
    CoreSettings::CoreSettings( )
    {
        // set initial values
        this->screenSize[0] = SGE_DEF_SCREEN_WIDTH;
        this->screenSize[1] = SGE_DEF_SCREEN_HEIGHT;
    }
    
    GLint *CoreSettings::GetScreenSize( )
    {
        return this->screenSize;
    }
    
    void CoreSettings::SetScreenSize( GLint screenWidth, GLint screenHeight )
    {
        this->screenSize[0] = screenWidth;
        this->screenSize[1] = screenHeight;
    }
}
