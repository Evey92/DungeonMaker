#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <time.h>  
#include "RoomCell.h"
#include <iostream>
#include "VectorMath.h"
#include <algorithm>

class DungeonControl
{
public:
	const int totalRooms = 69;
	const double PI = 3.14;
	XVECTOR2 m_mapCenter;
	std::vector<RoomCell> m_roomsInGrid;
	

	DungeonControl();
	~DungeonControl();
	
	XVECTOR2  GetRandomPointInCircle(float radius);
	XVECTOR2 SeparateRooms(RoomCell* room);
	void ComputeSeparation();
	void GenerateRooms(sf::RenderWindow* window);
	void SetMapCenter(int width, int height);
};

