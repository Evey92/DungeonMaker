#include "stdafx.h"
#include "DungeonControl.h"
#include "GameObject.h"


DungeonControl::DungeonControl()
{
	//srand(time(NULL));
}


DungeonControl::~DungeonControl()
{
}

XVECTOR2 DungeonControl::GetRandomPointInCircle(float radius)
{
	XVECTOR2 position;

	float r = rand() % (int)radius;
	float angle = (((float)rand()) / (float)RAND_MAX);
	angle *= 2 * PI;
	float x = r * cos(angle);
	float y = r * sin(angle);
	position.x = x + m_mapCenter.x;
	position.y = y + m_mapCenter.y;

	
	std::cout << "X: " << position.x << " Y: " << position.y << std::endl;
	return position;
}

void DungeonControl::GenerateRooms(sf::RenderWindow* window)
{

	for (int i = 0; i < totalRooms; i++)
	{
		RoomCell room;
		XVECTOR2 roomSize(rand() % 300 + 50, rand() % 200 + 50);
		XVECTOR2 roomPosition(GetRandomPointInCircle(100));
		room.setCell(roomSize.x, roomSize.y, roomPosition, window);
		room.m_Id = i + 1;
		m_roomsInGrid.push_back(room);
	}
	std::cout<<"LLegue hasta aquí antes de morir :v"<< std::endl;
}

void DungeonControl::SetMapCenter(int width, int height)
{
	m_mapCenter.x = width / 2;
	m_mapCenter.y = height / 2;
}

XVECTOR2 DungeonControl::SeparateRooms(RoomCell* room)
{
	int totalNeighbors = 0;
	XVECTOR2 separationVec;

	//for(m_roomIterator = m_roomsInGrid.begin(); m_roomIterator != m_roomsInGrid.end(); m_roomIterator++)
	for(RoomCell currentRoom : m_roomsInGrid)
	{
		//RoomCell* currentRoom;
		
			float roomdistance = (currentRoom.m_center - room->m_center).Length();

		if (
			((currentRoom.m_position.x > room->m_position.x && currentRoom.m_position.x < room->m_position.x + room->m_width) || (currentRoom.m_position.x + currentRoom.m_width > room->m_position.x  && currentRoom.m_position.x < room->m_position.x)) &&
			((currentRoom.m_position.y > room->m_position.y && currentRoom.m_position.y < room->m_position.y + room->m_height)|| (currentRoom.m_position.y + currentRoom.m_height > room->m_position.y && currentRoom.m_position.y < room->m_position.y)))
		{
			separationVec += (currentRoom.m_center - room->m_center);
			++totalNeighbors;
		}
	}
	if (totalNeighbors != 0)
	{
		separationVec /= totalNeighbors;
		separationVec *= -1;
		separationVec.Normalize();
		separationVec *= 2.0f;
	}
	
	return separationVec;
}

void DungeonControl::ComputeSeparation()
{
	std::cout << "Separando alv" << std::endl;
	for (int i = 0; i < m_roomsInGrid.size(); ++i)
	{
		m_roomsInGrid[i].m_neighborRooms = m_roomsInGrid;
	}

	int roomsSeparating = 0;
	do
	{
		roomsSeparating = 0;
		for (auto room : m_roomsInGrid)
		{
			if (room.isColliding(m_roomsInGrid))
			{
				room.m_position += SeparateRooms(&room);
				room.UpdatePosition();
				++roomsSeparating;
			}

		}
	} while (roomsSeparating != 0);

}