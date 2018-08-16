#include "stdafx.h"
#include "RoomCell.h"


RoomCell::RoomCell()
{

}


RoomCell::~RoomCell()
{
}

void RoomCell::setCell(int width, int height, XVECTOR2 pos, sf::RenderWindow* window)
{
	m_width = width;
	m_height = height;
	computeCenter();
	m_cellRectangle.setSize(sf::Vector2f(m_width, m_height));
	m_cellRectangle.setPosition(pos.x - m_width/2, pos.y - m_height/2);
	m_position = pos;
	computeCenter();
	m_cellRectangle.setOutlineThickness(3);
	m_cellRectangle.setFillColor(sf::Color::Blue);
	m_cellRectangle.setOutlineColor(sf::Color::White);
	std::cout << "Tamaño en X: " << m_width << " Y: " << m_height << std::endl;
	SetNode(window);

}

void RoomCell::UpdatePosition()
{
	m_cellRectangle.setPosition(m_position.x, m_position.y);
	//SetNode();
	//m_Node.setPosition(IDVtoSFML(m_roomCenter - XVECTOR2(2.5f, 2.5f)));
}

void RoomCell::computeCenter()
{
	m_center.x = m_position.x;
	m_center.y = m_position.y;
}

void RoomCell::SetNode(sf::RenderWindow* window)
{
	m_Node.setRadius(10);
	m_Node.setFillColor(sf::Color::Red);
	m_Node.setPosition(sf::Vector2f(m_center.x-10, m_center.y-10));
	m_Node.setOutlineThickness(3);
	m_Node.setOutlineColor(sf::Color::White);
	//window->draw(m_Node);
	std::cout<< "Hola, se debio haber pintado un circulo rojo en: (" <<m_center.x <<", " << m_center.y <<")" << std::endl;
}

bool RoomCell::isColliding(std::vector<RoomCell> neighbors)
{
	for (int i = 0; i < neighbors.size(); ++i)
	{
		if (neighbors[i].m_Id != m_Id)
		{
			if (
				((neighbors[i].m_position.x > m_position.x && neighbors[i].m_position.x < m_position.x + m_width) ||
				(neighbors[i].m_position.x + neighbors[i].m_width > m_position.x && neighbors[i].m_position.x < m_position.x)) &&
					((neighbors[i].m_position.y > m_position.y && neighbors[i].m_position.y < m_position.y + m_height) ||
				(neighbors[i].m_position.y + neighbors[i].m_height > m_position.y && neighbors[i].m_position.y < m_position.y)))
			{
				return true;
			}
		}
	}
	return false;
}