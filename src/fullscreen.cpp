#include <raylib.h>
#include "fullscreen.hpp"

void ToggleFullScreenWindow(int windowWidth , int windowHeight)
{
    if(!IsWindowFullscreen())
    {
        int monitor = GetCurrentMonitor();
        SetWindowSize(GetMonitorWidth(monitor), GetMonitorHeight(monitor));
        ToggleFullscreen();
    }
    else
    {
        ToggleFullscreen();
        SetWindowSize(windowWidth,windowHeight);
    }

}