#pragma once

#include <assert.h>
#include <math.h>

using namespace std;

class Vector
{
public:
	Vector() { x = y = z = 0.f; };
	Vector(float xx, float yy, float zz)
		: x(xx), y(yy), z(zz) { Assert(!HasNaNs());	};
	bool HasNaNs() const { return isnan(x) || isnan(y) || isnan(z); };

	//Operation Functions
	// SUM
	Vector operator+(const Vector &v) const {
		return Vector(x + v.x, y + v.y, z + v.z);
	}

	Vector& operator+=(const Vector &v) {
		x += v.x; y += v.y; z += v.z;
		return *this;
	}
	// SUBTRACTION
	// negative
	Vector operator-() const { return Vector(-x, -y, -z); };

	Vector operator-(const Vector &v) const {
		return Vector(x - v.x, y - v.y, z - v.z);
	}

	Vector& operator-=(const Vector &v) {
		x -= v.x; y -= v.y; z -= v.z;
		return *this;
	}
	//  MULTIPLY
	Vector operator*(float f) const {
		return Vector(f*x, f*y, f*z);
	};

	Vector &operator*=(float f) {
		x *= f; y *= f; z *= f;
		return *this;
	};
	// DIVISION
	Vector operator/(float f) const {
		Assert(f != 0);
		float inv = 1.f / f;
		return Vector(x * inv, y * inv, z * inv);
	};

	Vector &operator/=(float f) {
		Assert(f != 0);
		float inv = 1.f / f;
		x *= inv; y *= inv; z *= inv;
		return *this;
	};

	//LOOP ACCESS
	float operator[](int i) const {
		Assert(i >= 0 && i <= 2);
		return (&x)[i];
	};

	float &operator[](int i) {
		Assert(i >= 0 && i <= 2);
		return (&x)[i];
	};


	//INLINES
	//inline Vector operator*(float f, const Vector &v) { return v*f; };

	~Vector() {};

	float x, y, z;
};

