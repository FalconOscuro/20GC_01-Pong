#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SDL2/SDL_keycode.h>

enum class Key
{
    ZERO,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N,
    O,
    P,
    Q,
    R,
    S,
    T,
    U,
    V,
    W,
    X,
    Y,
    Z,
    ARROW_UP,
    ARROW_DOWN,
    ARROW_LEFT,
    ARROW_RIGHT
}; // enum class Key

bool ConvertSDLKey(const SDL_KeyCode& keycode, Key& out);

#endif // KEYBOARD_H