#include "Bat.h"

Bat::Bat(float startX, float startY) : m_Position(startX, startY)
{
	m_Shape.setSize(sf::Vector2f(50, 5));
	m_Shape.setPosition(m_Position);
}

Bat::~Bat()
{
}

void Bat::Update(sf::Time dt)
{
	if (m_IsMovingLeft)
	{
		m_Position.x -= m_speed * dt.asSeconds();
	}
	else if (m_IsMovingRight)
	{
		m_Position.x += m_speed * dt.asSeconds();
	}
	m_Shape.setPosition(m_Position);
}

void Bat::MoveRight()
{
	m_IsMovingRight = true;
}

void Bat::MoveLeft()
{
	m_IsMovingLeft = true;
}

void Bat::StopRight()
{
	m_IsMovingRight = false;
}

void Bat::StopLeft()
{
	m_IsMovingLeft = false;
}
