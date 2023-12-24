#pragma once
#include <SFML/Graphics.hpp>

class Fighter
{
private:
	enum State
	{
		idle,
		preAttack,
		attack,
		postAttack,
		preDefend,
		defend,
		postDefend
	};
	State currentState;
	int stateFramesElapsed; //the number of frames that have elapsed in the current state

	sf::RectangleShape hitbox;
	sf::RectangleShape attackHitbox;
	sf::Rect<float> collisionBox;
	sf::Rect<float> attackCollisionBox;

	int controllerNumber;

	void move(float offset);

public:
	Fighter(int controllerNum, sf::Vector2f position);
	void draw(sf::RenderWindow& window);
	void handleInput();
	void checkAttack(Fighter& b);
};