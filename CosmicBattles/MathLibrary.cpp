#include "MathLibrary.h"
#include <cmath>

float MathLibrary::Pi = 3.14f;
float MathLibrary::PlaneAngle = 180.f;

float MathLibrary::calculateSine(float in_angle, float in_rotation_shift)
{
	return std::sin((in_angle - in_rotation_shift) * (Pi / PlaneAngle));
}

float MathLibrary::calculateCosine(float in_angle, float in_rotation_shift)
{
	return std::cos((in_angle - in_rotation_shift) * (Pi / PlaneAngle));
}