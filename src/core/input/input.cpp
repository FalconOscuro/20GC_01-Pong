#include "core/input/input.hpp"

Input::Input()
{
    m_InputMap = std::unordered_map<Key, InputState>();
}

void Input::ParseInput(const SDL_KeyboardEvent& event)
{
    Key keycode;
    InputState state(event);

    if (!ConvertSDLKey((SDL_KeyCode)event.keysym.sym, keycode))
        return;

    auto found = m_InputMap.find(keycode);

    if (found != m_InputMap.end())
    {
        found->second = state;
        return;
    }

    m_InputMap.insert({keycode, state});
}

bool Input::IsKeyPressed(const Key& keycode) const
{
    auto found = m_InputMap.find(keycode);
    if (found == m_InputMap.end())
        return false;

    return found->second.Type == InputType::KEY_DOWN;
}

Input* Input::s_Singleton = nullptr;

Input* Input::Get()
{
    if (s_Singleton == nullptr) {
        s_Singleton = new Input();
    }
        
    return s_Singleton;
}