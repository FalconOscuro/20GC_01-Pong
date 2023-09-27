#ifndef VECTOR2_H
#define VECTOR2_H

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

    Vector2 operator*=(const float& s);
    Vector2 operator/=(const float& s);

    float X;
    float Y;
};


#endif // VECTOR2_H