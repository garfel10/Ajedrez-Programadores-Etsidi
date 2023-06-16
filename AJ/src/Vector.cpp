#include "Vector.h"

Vector::Vector()
{
	x = 0;
	y = 0;
}

Vector::Vector(int posx, int posy)
{
	x = posx;
	y = posy;
}

bool Vector::operator==(const Vector& vector)
{
	if (vector.x == x && vector.y == y)
	{
		return true;

	}
	else
		return false;
}

bool Vector::operator!=(const Vector& vector)
{
	if (vector.x != x || vector.y != y)
	{
		return true;

	}
	else
		return false;
}

Vector Vector:: operator+(Vector vector)
{
	Vector solucion;
	solucion.x = x + vector.x;
	solucion.y = y + vector.y;

	return solucion;
}