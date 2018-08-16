#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <vector>
#include "VectorMath.h"
#include <string>
#include <math.h>
#include <queue>
#include <time.h>
#include <iostream>

class GameObject
{

public:
	sf::Vector2f m_Position;	

	GameObject();
	~GameObject();
	void SetPosition(float x, float y);
	void SetPosition(sf::Vector2f);

};

