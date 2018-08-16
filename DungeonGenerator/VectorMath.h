#pragma once
#include <SFML\Graphics.hpp>

struct XVECTOR2 {
	XVECTOR2() :x(0.0f), y(0.0f) {}
	XVECTOR2(const float *vf) :x(vf[0]), y(vf[1]) {}
	XVECTOR2(const XVECTOR2& v) :x(v.x), y(v.y) {}
	XVECTOR2(const float &xp, const float &yp) :x(xp), y(yp) {}

	XVECTOR2 & operator= (const XVECTOR2 & other) {
		this->x = other.x; this->y = other.y;
		return *this;
	}
	XVECTOR2 & operator= (XVECTOR2 & other) {
		this->x = other.x; this->y = other.y;
		return *this;
	}

	operator float* ();
	operator const float* () const;

	XVECTOR2& operator += (const XVECTOR2&);
	XVECTOR2& operator -= (const XVECTOR2&);
	XVECTOR2& operator *= (float);
	XVECTOR2& operator /= (float);

	XVECTOR2 operator + () const;
	XVECTOR2 operator - () const;

	XVECTOR2 operator + (const XVECTOR2&) const;
	XVECTOR2 operator - (const XVECTOR2&) const;
	XVECTOR2 operator * (float) const;
	XVECTOR2 operator / (float) const;
	XVECTOR2 normalized();
	bool operator == (const XVECTOR2&) const;
	bool operator != (const XVECTOR2&) const;

	void Normalize();
	float Length();

	union {
		float	 v[2];

		struct {
			float x;
			float y;
		};
	};
};

class VectorMath
{
public:
	VectorMath();
	~VectorMath();

	sf::Vector2f Normalize(sf::Vector2f& vector);
	float Length(sf::Vector2f& vector);
};

