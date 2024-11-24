#pragma once
#include <SFML/Graphics.hpp>

class Bat
{
public:
	Bat(float startX, float startY);
	~Bat();
	void Update(sf::Time dt);
	sf::FloatRect GetPosition() { return m_Shape.getGlobalBounds(); }
	sf::RectangleShape GetShape() { return m_Shape; }
	void MoveRight();
	void MoveLeft();
	void StopRight();
	void StopLeft();


private:
	sf::Vector2f m_Position;
	sf::RectangleShape m_Shape;
	float m_speed = 1000.0f;
	bool m_IsMovingRight = false;
	bool m_IsMovingLeft = false;
};

