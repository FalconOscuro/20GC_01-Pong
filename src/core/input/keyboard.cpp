#include "core/input/keyboard.h"

bool ConvertSDLKey(const SDL_KeyCode& keycode, Key& out)
{
    switch (keycode)
    {
    case SDLK_UP:
        out = Key::ARROW_UP;
        return true;

    case SDLK_DOWN:
        out = Key::ARROW_DOWN;
        return true;

    case SDLK_w:
        out = Key::W;
        return true;

    case SDLK_s:
        out = Key::S;
        return true;
    
    default:
        return false;
    }
}