#include "Vec3.h"

namespace SIE {
	Vec3::Vec3(float x,float y,float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	void Vec3::operator-()
	{
		x = -x;
		y = -y;
		z = -z;
	}

	Vec3 *Vec3::operator+(Vec3 & r) {
		return new Vec3(x + r.x, y + r.y, z + r.z);
	}

	void Vec3::operator+=(Vec3 & r)
	{
		x += r.x;
		y += r.y;
		z += r.z;
	}

	Vec3 * SIE::Vec3::operator-(Vec3 & r)
	{
		return new Vec3(x - r.z, y - r.y, z - r.z);
	}

	void SIE::Vec3::operator-=(Vec3 & r)
	{
		x -= r.x;
		y -= r.y;
		z -= r.z;
	}

	Vec3 * SIE::Vec3::operator*(Vec3 & r)
	{
		return new Vec3(x*r.x, y*r.y, z*r.z);
	}

	void SIE::Vec3::operator*=(Vec3 & r)
	{
		x *= r.x;
		y *= r.y;
		z *= r.z;
	}
}
