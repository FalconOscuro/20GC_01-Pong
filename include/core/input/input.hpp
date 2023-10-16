#ifndef INPUT_HPP
#define INPUT_HPP

#include "inputstate.h"
#include "keyboard.h"

#include <unordered_map>
#include <SDL2/SDL_events.h>

/// @brief Stores current input state
class Input
{
protected:

    Input();

    static Input* s_Singleton;

public:

    void ParseInput(const SDL_KeyboardEvent& event);

    bool IsKeyPressed(const Key& keycode)const;

    static Input* Get();

private:

    std::unordered_map<Key, InputState> m_InputMap;
}; // class Input

#endif // INPUT_HPP