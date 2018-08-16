#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::SetPosition(float x, float y)
{
	m_Position.x = x;
	m_Position.y = y;
}

void GameObject::SetPosition(sf::Vector2f pos)
{
	m_Position = pos;
}
