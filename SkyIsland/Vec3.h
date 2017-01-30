#pragma once
namespace SIE {
	class Vec3
	{
	public:
		float x, y, z;

		Vec3(float x,float y,float z);

		void operator-();
		Vec3 *operator+(Vec3 &r);
		void operator+=(Vec3 &r);
		Vec3 *operator-(Vec3 &r);
		void operator-=(Vec3 &r);
		Vec3 *operator*(Vec3 &r);
		void operator*=(Vec3 &r);
	};
}

