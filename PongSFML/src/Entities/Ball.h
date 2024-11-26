#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
public:
	Ball(float startX, float startY);
	~Ball();
	sf::FloatRect GetPosition() { return m_Shape.getGlobalBounds(); }
	sf::RectangleShape GetShape() { return m_Shape; }
	float GetXVelocity() { return m_DirectionX; }
	void ReboundSides();
	void ReboundBatOrTop();
	void ReboundBottom();
	void Update(sf::Time dt);

private:
	sf::Vector2f m_Position;
	sf::RectangleShape m_Shape;
	float m_Speed = 800.0f;
	float m_DirectionX = 0.2f;
	float m_DirectionY = 0.2f;
};
