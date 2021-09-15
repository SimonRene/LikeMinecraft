#pragma once

#include "../include/window.h"


namespace GE {


    class Time
    {
    public:

        static double deltaTime();


    private:
        /* data */

        // per-frame time logic
        // --------------------
        static double s_currentFrame;
        static double s_deltaTime;
        static double s_lastFrame;


        static void update(double currentTime);

    private:
        Time(/* args */);
        ~Time();


        friend GE::Window;
    };
    
}