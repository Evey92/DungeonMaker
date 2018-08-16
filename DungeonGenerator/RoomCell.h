#pragma once
#include "GameObject.h"


class RoomCell : public GameObject
{

public:
	int m_Id;
	int m_width, m_height;
	float nodeRadius = 2;
	XVECTOR2 m_center;
	XVECTOR2 m_position;
	std::vector<RoomCell> m_neighborRooms;
	sf::RectangleShape m_cellRectangle;
	sf::CircleShape m_Node;
	RoomCell();
	~RoomCell();
	bool isColliding(std::vector<RoomCell> neighbors);

	void setCell(int width, int height, XVECTOR2 pos, sf::RenderWindow* window);
	void UpdatePosition();
	void SetNode(sf::RenderWindow* window);
	void computeCenter();
};

