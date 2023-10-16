#ifndef INPUTSTATE_H
#define INPUTSTATE_H

#include <SDL2/SDL_events.h>

enum class InputType
{
    KEY_UP,
    KEY_DOWN
};

struct InputState
{
    InputState(const SDL_KeyboardEvent& event);

    InputType Type;
};

#endif // INPUTSTATE_H