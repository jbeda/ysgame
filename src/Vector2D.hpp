#pragma once

class Vector2f
{
public:
    float x;
    float y;

    Vector2f() : x(0), y(0) {}
    Vector2f(float x_, float y_) : x(x_), y(y_) {}

    static Vector2f FromAngle(float angle, float mag = 1);

    Vector2f& Add(const Vector2f& vec) { x += vec.x; y += vec.y; return *this; }
    Vector2f& operator+=(Vector2f& v) { Add(v); return *this; }

    Vector2f& Sub(const Vector2f& vec) { x -= vec.x; y -= vec.y; return *this; }
    Vector2f& operator-=(Vector2f& v) { Sub(v); return *this;  }

    Vector2f& Mul(float f) { x *= f; y *= f; return *this; }
    Vector2f& operator*=(float f) { Mul(f); return *this; }

    Vector2f& Div(float f) { x /= f; y /= f; return *this; }
    Vector2f& operator/=(float f) { Div(f); return *this; }

    // Unary -
    Vector2f operator-() { return Vector2f(-x, -y); }

    friend Vector2f operator+(Vector2f& v1, const Vector2f& v2) {
        return Vector2f(v1.x + v2.x, v1.y + v2.y);
    }

    friend Vector2f operator-(Vector2f& v1, const Vector2f& v2) {
        return Vector2f(v1.x - v2.x, v1.y - v2.y);
    }

    friend Vector2f operator*(Vector2f& v1, float f) {
        return Vector2f(v1.x * f, v1.y * f);
    }
    friend Vector2f operator*(float f, Vector2f& v1) { return v1 * f; }

    friend Vector2f operator/(Vector2f& v1, float f) {
        return Vector2f(v1.x / f, v1.y / f);
    }

    // The magnitude of this vector, squared
    float MagSq();
    // The magnitude of this vector
    float Mag();
    // Normalize this vector to a unit vector
    Vector2f& Normalize();
    // Ensure this vector has a magnitude no longer than f
    Vector2f& Limit(float f);
    // Set the magnitude of this vector to f
    Vector2f& SetMag(float f);

    // The dot product of this vector and another vector. This is v1.x*v2.x + v1.y*v2.y
    float Dot(Vector2f& v);
    
    // The distance between this vector and v
    float Dist(Vector2f& v);

    // Calculate the angle of rotation for this vector, in radians
    float Heading();

    // Rotate this vector by an angle (Radians). Magnitude remains the same
    Vector2f& Rotate(float f);

    // Determine the angle (in radians) between this vector and v
    float angleBetween(Vector2f& v);

    // TODO: lerp
};

