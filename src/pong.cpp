#include "pong.h"

#include "nodes/drawablerect.h"
#include "iterators/dfs.h"
#include "visitors/viewportcull.h"

#include "builders/pongbuilder.h"

#include <iostream>

Pong::Pong(int width, int height)
{
    m_Ready = false;
    m_Running = false;

    m_Wnd = NULL;
    m_Renderer = NULL;
    m_DisplayTex = NULL;

    m_Width = width;
    m_Height = height;
}

Pong::~Pong()
{
    Close();

    // Delete nodes
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

    else if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
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

    m_DisplayTex = SDL_CreateTexture(
        m_Renderer, 
        SDL_PIXELFORMAT_ABGR8888,
        SDL_TEXTUREACCESS_STREAMING,
        m_Width,
        m_Height
    );

    if (m_DisplayTex == NULL)
    {
        std::cerr << "Failed to create SDL Texture\n";
        return false;
    }

    m_Root = GetGame(Vector2(m_Width, m_Height));

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

    SDL_DestroyTexture(m_DisplayTex);
    m_DisplayTex = NULL;

    SDL_DestroyRenderer(m_Renderer);
    m_Renderer = NULL;

    SDL_DestroyWindow(m_Wnd);
    m_Wnd = NULL;

    SDL_Quit();
}

/// @brief Game entry point
void Pong::Run()
{
    if (!CheckReady())
        return;

    else if (m_Running)
    {
        std::cerr << "Object already active\n";
        return;
    }

    m_LastUpdate = std::chrono::high_resolution_clock::now();
    m_Running = true;
    while (m_Running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event)) 
            switch (event.type)
        {
        case SDL_QUIT:
            m_Running = false;
            break;
        
        default:
            break;
        }

        Update();
        
        Render();
    }
    m_Running = false;
}

bool Pong::CheckReady() const
{
    if (!m_Ready)
        std::cerr << "Object not initialized\n";

    return m_Ready;
}

void Pong::Render()
{
    if (!CheckReady())
        return;
    
    // Update texture
    void* pixels;
    int pitch;
    if (SDL_LockTexture(m_DisplayTex, NULL, &pixels, &pitch) < 0)
    {
        std::cerr << "Failed to lock SDL Texture\n";
        return;
    }

    ViewportCull viewportCull = ViewportCull(Rect(Vector2(), 
        Vector2(m_Width, m_Height)));
    Iterator_DFS iterator = Iterator_DFS(m_Root);

    while (!iterator.Finished())
        iterator.Next()->Accept(&viewportCull);
    
    std::vector<const DrawableRect*> drawables = viewportCull.GetDrawables();

    for (int i = 0; i < m_Height; i++)
    {
        // Pointer to current target pixel
        Uint32* pX = (Uint32*)((Uint8*)pixels + i * pitch);
        for (int j = 0; j < m_Width; j++)
        {
            Vector2 pos = Vector2(j, i);
            SDL_Colour colour = SDL_Colour{0, 0, 0, 255};

            for (size_t k = 0; k < drawables.size(); k++)
                if (drawables[k]->Rectangle.ContainsPoint(pos))
                    colour = SDL_Colour{255, 255, 255, 255};           

            // Assign current pixel value, then increment to next in row
            *pX++ = (0xFF000000|(colour.r<<16)|(colour.g<<8)|(colour.b));
        }
    }

    SDL_UnlockTexture(m_DisplayTex);

    SDL_RenderClear(m_Renderer);
    SDL_RenderCopy(m_Renderer, m_DisplayTex, NULL, NULL);
    SDL_RenderPresent(m_Renderer);
}

void Pong::Update()
{
    using namespace std::chrono;

    high_resolution_clock::time_point now = high_resolution_clock::now();
    duration<float> deltaTime = duration_cast<duration<float>>(now - m_LastUpdate);
    m_LastUpdate = now;
    
    Iterator_DFS iterator = Iterator_DFS(m_Root);

    while (!iterator.Finished())
        iterator.Next()->Update(deltaTime.count());
}