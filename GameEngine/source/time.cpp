#include "../include/time.h"

namespace GE {

double Time::s_deltaTime = 0.0;
double Time::s_lastFrame = 0.0;

Time::Time(/* args */)
{
}

Time::~Time()
{
}

void Time::update(double currentTime) {
    s_deltaTime = currentTime - s_lastFrame;
    s_lastFrame = currentTime;
}

double Time::deltaTime() {
    return s_deltaTime;
}

}