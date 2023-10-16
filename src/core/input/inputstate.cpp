#include "core/input/inputstate.h"

InputState::InputState(const SDL_KeyboardEvent& event)
{
    switch (event.state)
    {
    case SDL_PRESSED:
        Type = InputType::KEY_DOWN;
        break;;
    
    case SDL_RELEASED:
        Type = InputType::KEY_UP;
        break;
    }
}