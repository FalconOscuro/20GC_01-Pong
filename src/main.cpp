#include "pong.h"

#include "SDL2/SDL.h"

#include <iostream>

int main()
{
    Pong pong = Pong(640, 480);

    pong.Init();
    pong.Run();
    pong.Close();

    return 0;
}