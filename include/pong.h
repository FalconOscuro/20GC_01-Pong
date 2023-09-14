#ifndef PONG_H
#define PONG_H

#include "SDL2/SDL.h"

class Pong
{
public:
    Pong(int width, int height);
    ~Pong();

    bool Init();
    void Close();

    void Run();

private:
    /// @brief Has completed Initialization step
    bool m_Ready;

    bool m_Running;

    SDL_Window* m_Wnd;
    SDL_Renderer* m_Renderer;

    int m_Width;
    int m_Height;
};


#endif // PONG_H