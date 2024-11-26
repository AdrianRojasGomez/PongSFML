#include "Ball.h"

Ball::Ball(float startX, float startY) : m_Position(startX, startY)
{
	m_Shape.setSize(sf::Vector2f(10, 10));
	m_Shape.setPosition(m_Position);
}

Ball::~Ball()
{
}

void Ball::ReboundSides()
{
	m_DirectionX = -m_DirectionX;
}

void Ball::ReboundBatOrTop()
{
	m_DirectionY = -m_DirectionY;
}

void Ball::ReboundBottom()
{
	m_Position.y = 0;
	m_Position.x = 500;
	m_DirectionX = -m_DirectionY;
}

void Ball::Update(sf::Time dt)
{
	m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();
	m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();

	m_Shape.setPosition(m_Position);
}
