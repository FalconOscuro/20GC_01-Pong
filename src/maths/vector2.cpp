#include "maths/vector2.h"

Vector2::Vector2()
{}

Vector2::Vector2(float x, float y):
    X(x), Y(y)
{}

Vector2 Vector2::operator+(const Vector2& v) const
{
    return Vector2(X + v.X, Y + v.Y);
}

Vector2 Vector2::operator-(const Vector2& v) const
{
    return Vector2(X - v.X, Y - v.Y);
}

Vector2 Vector2::operator*(const float& s) const
{
    return Vector2(X * s, Y * s);
}

Vector2 Vector2::operator/(const float& s) const
{
    return Vector2(X / s, Y / s);
}

void Vector2::operator+=(const Vector2& v)
{
    X += v.X;
    Y += v.Y;
}

void Vector2::operator-=(const Vector2& v)
{
    X -= v.X;
    Y -= v.Y;
}

void Vector2::operator*=(const float& s)
{
    X *= s;
    Y *= s;
}

void Vector2::operator/=(const float& s)
{
    X /= s;
    Y /= s;
}