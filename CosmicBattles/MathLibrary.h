#ifndef MATH_LIBRARY_H
#define MATH_LIBRARY_H

#include "SFML/System/Vector2.hpp"

class MathLibrary
{
public:
	static float calculateSine(float in_angle, float in_rotation_shift = 0.f);
	static float calculateCosine(float in_angle, float in_rotation_shift = 0.f);

	static float calculateAngle(sf::Vector2f& in_start, sf::Vector2f& in_end);
private:
	static float Pi;
	static float PlaneAngle;
};
#endif