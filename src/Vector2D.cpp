#include "Vector2D.hpp"

#include <algorithm>
#include <cmath>

Vector2f Vector2f::FromAngle(float angle, float mag)
{
	return Vector2f(mag * cos(angle), mag * sin(angle));
}

float Vector2f::MagSq() {
	return x * x + y * y;
}

float Vector2f::Mag() {
	return sqrt(MagSq());
}

Vector2f& Vector2f::Normalize() {
	float len = Mag();
	return Div(len);
}

Vector2f& Vector2f::Limit(float f) {
	float mSq = MagSq();
	if (mSq > f * f) {
		Div(sqrt(mSq)).Mul(f);
	}
	return *this;
}

Vector2f& Vector2f::SetMag(float f) {
	return Normalize().Mul(f);
}

float Vector2f::Dot(Vector2f& v) {
	return x * v.x + y * v.y;
}

float Vector2f::Dist(Vector2f&v) {
	return Vector2f(v).Sub(*this).Mag();
}

float Vector2f::Heading() {
	return atan2(y, x);
}

Vector2f& Vector2f::Rotate(float f)
{
	float newHeading = Heading() + f;
	float mag = Mag();
	x = cos(newHeading) * mag;
	y = sin(newHeading) * mag;
	return *this;
}

float Vector2f::angleBetween(Vector2f & v)
{
	float dotmagmag = Dot(v) / (Mag() * v.Mag());

	// We need to ensure that dotmagmag is between -1 and 1 here
	return acos(std::min(1.0f, std::max(-1.0f, dotmagmag)));
}


