#pragma once

class Vector
{
public:
	int x;
	int y;

	Vector();
	Vector(int posx, int posy);

	bool operator == (const Vector& vector);
	Vector operator+(Vector vector);
	bool operator!=(const Vector& vector);

};
