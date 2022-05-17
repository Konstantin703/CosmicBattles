#ifndef MATH_LIBRARY_H
#define MATH_LIBRARY_H

class MathLibrary
{
public:
	static float calculateSine(float in_angle, float in_rotation_shift = 0.f);
	static float calculateCosine(float in_angle, float in_rotation_shift = 0.f);
private:
	static float Pi;
	static float PlaneAngle;
};
#endif