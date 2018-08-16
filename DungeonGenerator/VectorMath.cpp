#include "stdafx.h"
#include "VectorMath.h"


VectorMath::VectorMath()
{
}


VectorMath::~VectorMath()
{
}

XVECTOR2::operator float* ()
{
	return &x;
}
XVECTOR2::operator const float* () const
{
	return &x;
}

XVECTOR2& XVECTOR2:: operator+=(const XVECTOR2& other)
{
	this->x = this->x + other.x; this->y = this->y + other.y; return *this;
}
XVECTOR2& XVECTOR2::operator -= (const XVECTOR2& other)
{
	this->x = this->x - other.x; this->y = this->y - other.y; return *this;
}
XVECTOR2& XVECTOR2::operator *= (float times)
{
	this->x = this->x * times; this->y = this->y * times; return *this;
}
XVECTOR2& XVECTOR2::operator /= (float times)
{
	this->x = this->x / times; this->y = this->y / times; return *this;
}

XVECTOR2 XVECTOR2::operator + () const
{
	return *this;
}
XVECTOR2 XVECTOR2::operator - () const
{
	return XVECTOR2(-x, -y);
}

XVECTOR2 XVECTOR2::operator + (const XVECTOR2& other) const
{
	return XVECTOR2(x + other.x, y + other.y);
}
XVECTOR2 XVECTOR2::operator - (const XVECTOR2& other) const
{
	return XVECTOR2(x - other.x, y - other.y);
}
XVECTOR2 XVECTOR2::operator * (float times) const
{
	return XVECTOR2(x * times, y * times);
}
XVECTOR2 XVECTOR2::operator / (float times) const
{
	return XVECTOR2(x / times, y / times);
}

bool XVECTOR2::operator == (const XVECTOR2& other) const
{
	if (this->x == other.x&&this->y == other.y) return true;
	return false;
}
bool XVECTOR2::operator != (const XVECTOR2& other) const
{
	if (this->x != other.x&&this->y != other.y) return true;
	return false;
}
XVECTOR2 XVECTOR2::normalized()
{
	XVECTOR2 norm;
	float v = sqrt((this->x * this->x) + (this->y * this->y));
	norm.x = this->x / v;
	norm.y = this->y / v;
	return norm;
}
void XVECTOR2::Normalize()
{

	float v = sqrt((this->x * this->x) + (this->y * this->y)); this->x = this->x / v; this->y = this->y / v;
}
float XVECTOR2::Length()
{
	return sqrt((this->x * this->x) + (this->y * this->y));
}

//sf::Vector2f VectorMath::Normalize(const sf::Vector2f& vector)
//{
//	float length = sqrt((vector.x * vector.x) + (vector.y * vector.y));
//	if (length != 0)
//		return sf::Vector2f(vector.x / length, vector.y / length);
//	else
//		return vector;
//}

//sf::Vector2f VectorMath::Normalize(sf::Vector2f& vector)
//{
//
//	float v = sqrt((vector.x * vector.x) + (vector.y * vector.y)); 
//	vector.x = vector.x / v;
//	vector.y = vector.y / v;
//	return vector;
//}
//float VectorMath::Length(sf::Vector2f& vector)
//{
//	return sqrt((vector.x * vector.x) + (vector.y * vector.y));
//}
//
//sf::Vector2f& +=(const sf::Vector2f& other)
//{
//	this->x = this->x + other.x; this->y = this->y + other.y; return *this;
//}

