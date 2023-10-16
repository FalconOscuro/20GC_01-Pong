#include "pong.h"

#include "SDL2/SDL.h"

#include <iostream>

int main()
{
    Pong pong = Pong(640, 480);

    if (!pong.Init())
        return 0;
        
    pong.Run();
    pong.Close();

    return 0;
}