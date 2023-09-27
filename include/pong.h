#ifndef PONG_H
#define PONG_H

#include "nodes/node.h"

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

    bool CheckReady() const;

    void Update();
    void Render();

    /// @brief Has completed Initialization step
    bool m_Ready;

    bool m_Running;

    SDL_Window* m_Wnd;
    SDL_Renderer* m_Renderer;
    SDL_Texture* m_DisplayTex;

    int m_Width;
    int m_Height;

    Node* m_Root;
};


#endif // PONG_H