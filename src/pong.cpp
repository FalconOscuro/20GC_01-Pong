#include "pong.h"

#include <iostream>

Pong::Pong(int width, int height)
{
    m_Ready = false;
    m_Running = false;

    m_Wnd = NULL;
    m_Renderer = NULL;

    m_Width = width;
    m_Height = height;
}

Pong::~Pong()
{
    Close();
}

/// @brief Initialize SDL components
/// @return Operation success state
bool Pong::Init()
{
    if (m_Ready)
    {
        std::cerr << "Object already initialized\n";
        return false;
    }

    else if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) !=0)
    {
        std::cerr << "Failed to initialize SDL\n";
        return false;
    }

    m_Wnd = SDL_CreateWindow(
        "Pong",
        SDL_WINDOWPOS_UNDEFINED, // No pre-defined window position
        SDL_WINDOWPOS_UNDEFINED,
        m_Width,
        m_Height,
        0 // No additional flags
    );

    if (m_Wnd == NULL)
    {
        std::cerr << "Failed to create SDL Window\n";
        return false;
    }

    m_Renderer = SDL_CreateRenderer(m_Wnd, -1, SDL_RENDERER_SOFTWARE);

    if (m_Renderer == NULL)
    {
        std::cerr << "Failed to create SDL Renderer\n";
        return false;
    }

    m_Ready = true;
    return true;
}

/// @brief Shut down SDL components
void Pong::Close()
{
    if (!m_Ready)
        return;

    m_Ready = false;
    m_Running = false;

    SDL_DestroyRenderer(m_Renderer);
    m_Renderer = NULL;

    SDL_DestroyWindow(m_Wnd);
    m_Wnd = NULL;

    SDL_Quit();
}

/// @brief Game entry point
void Pong::Run()
{
    if (!m_Ready)
    {
        std::cerr << "Object not initialized\n";
        return;
    }

    else if (m_Running)
    {
        std::cerr << "Object already active\n";
        return;
    }

    m_Running = true;
    while (m_Running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event)) switch (event.type)
        {
        case SDL_QUIT:
            m_Running = false;
            break;
        
        default:
            break;
        }
        
        // Rendering
        SDL_RenderClear(m_Renderer);
        SDL_RenderPresent(m_Renderer);
    }
    m_Running = false;
}