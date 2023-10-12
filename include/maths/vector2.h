#ifndef VECTOR2_H
#define VECTOR2_H

/// @brief 2D floating point vector
struct Vector2
{
public:
    Vector2();
    Vector2(float x, float y);

    Vector2 operator+(const Vector2& v) const;
    Vector2 operator-(const Vector2& v) const;

    Vector2 operator*(const float& s) const;
    Vector2 operator/(const float& s) const;

    void operator+=(const Vector2& v);
    void operator-=(const Vector2& v);

    void operator*=(const float& s);
    void operator/=(const float& s);

    float X;
    float Y;
}; // struct Vector2


#endif // VECTOR2_H