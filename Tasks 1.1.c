#define _USE_MATH_DEFINES 

#include <stdio.h>
#include <math.h>

double getB(const double x, const double y, const double z);
double getA(const double x, const double y, const double z);
/**
* @brief Точка входа в программу
* @
*/
int main()

{
	const double x = 2;
	const double y = 0.7;
	const double z = -1;

	printf("A = %lf", getA(x, y, z));
	printf("B = %lf", getB(x, y, z));
	return 0;
}
double getB(const double x, const double y, const double z)
{

	return	y*cos(cos(x*z*sin(sin(y)))) + 3;
}
double getA(const double x, const double y, const double z)
{
	return cbrt((x*y*z + fabs(y)));
}
