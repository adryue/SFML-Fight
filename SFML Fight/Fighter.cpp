#include <iostream>
#include "Fighter.h"

const float FIGHTER_WIDTH = 20;
const float FIGHTER_HEIGHT = 100;
const float ATTACK_WIDTH = 50;
const float ATTACK_HEIGHT = 10;

const float FIGHTER_MOVEMENT_SPEED_MULTIPLIER = 0.1;
const int FIGHTER_PREATTACK_SPEED = 20;
const int FIGHTER_ATTACK_SPEED = 20;
const int FIGHTER_POSTATTACK_SPEED = 20;
const int FIGHTER_PREDEFEND_SPEED = 20;
const int FIGHTER_DEFEND_SPEED = 20;
const int FIGHTER_POSTDEFEND_SPEED = 20;

const int DEADZONE = 10; //deadzone for the joysticks

Fighter::Fighter(int controllerNum, sf::Vector2f position)
{
	currentState = State::idle;
	stateFramesElapsed = 0;

	hitbox.setSize(sf::Vector2f(FIGHTER_WIDTH, FIGHTER_HEIGHT));
	hitbox.setFillColor(sf::Color::White);
	hitbox.setPosition(position);
	attackHitbox.setSize(sf::Vector2f(ATTACK_HEIGHT, ATTACK_HEIGHT));
	attackHitbox.setFillColor(sf::Color::Red);
	collisionBox.width = FIGHTER_WIDTH;
	collisionBox.height = FIGHTER_HEIGHT;
	attackCollisionBox.width = ATTACK_WIDTH;
	attackCollisionBox.height = ATTACK_HEIGHT;

	controllerNumber = controllerNum;
}

void Fighter::draw(sf::RenderWindow& window)
{
	window.draw(hitbox);
	//window.draw(attackHitbox);
}

void Fighter::move(float offset)
{
	hitbox.move(offset, 0);
	collisionBox.left += offset;
}

void Fighter::handleInput()
{
	switch (currentState)
	{
	//--------------------Idle state--------------------
	case idle:
		//movement
		if (abs(sf::Joystick::getAxisPosition(controllerNumber, sf::Joystick::X)) > DEADZONE)
		{
			move(sf::Joystick::getAxisPosition(controllerNumber, sf::Joystick::X) * FIGHTER_MOVEMENT_SPEED_MULTIPLIER);
		}

		//attack
		if (sf::Joystick::isButtonPressed(controllerNumber, 1))
		{
			currentState = State::preAttack;
		}

		//defend
		if (sf::Joystick::isButtonPressed(controllerNumber, 2))
		{
			currentState = State::preDefend;
		}

		break;
	//--------------------Attack states--------------------
	case preAttack:
		std::cout << controllerNumber << " pre attack";
		stateFramesElapsed++;
		if (stateFramesElapsed >= FIGHTER_PREATTACK_SPEED)
		{
			stateFramesElapsed = 0;
			currentState = State::attack;
		}
		break;
	case attack:
		std::cout << controllerNumber << " attack";
		stateFramesElapsed++;
		if (stateFramesElapsed >= FIGHTER_ATTACK_SPEED)
		{
			stateFramesElapsed = 0;
			currentState = State::postAttack;
		}
		break;
	case postAttack:
		std::cout << controllerNumber << " post attack";
		stateFramesElapsed++;
		if (stateFramesElapsed >= FIGHTER_POSTATTACK_SPEED)
		{
			stateFramesElapsed = 0;
			currentState = State::idle;
		}
		break;
	//--------------------Defend states--------------------
	case preDefend:
		std::cout << controllerNumber << " pre defend";
		stateFramesElapsed++;
		if (stateFramesElapsed >= FIGHTER_PREDEFEND_SPEED)
		{
			stateFramesElapsed = 0;
			currentState = State::defend;
		}
		break;
	case defend:
		std::cout << controllerNumber << " defend";
		stateFramesElapsed++;
		if (stateFramesElapsed >= FIGHTER_DEFEND_SPEED)
		{
			stateFramesElapsed = 0;
			currentState = State::postDefend;
		}
		break;
	case postDefend:
		std::cout << controllerNumber << " post defend";
		stateFramesElapsed++;
		if (stateFramesElapsed >= FIGHTER_POSTDEFEND_SPEED)
		{
			stateFramesElapsed = 0;
			currentState = State::idle;
		}
		break;
	default:
		break;
	}
	

	/*
	For gamecube controllers
	Left Joystick:
		X Axis (left is -74, right is 78) -80 88
		Y Axis (up is -84, down is 69) -85 76
	Right Joystick:
		Z Axis (down is -74, up is 69) -64 80
		R Axis (left is 61, right is -75) 69 -78
	Buttons:
		0: X
		1: A
		2: B
		3: Y
		4: Left Trigger
		5: Right Trigger
		7: Z Trigger
		9: Start
		12: Up
		13: Right
		14: Down
		15: Left
	*/
}

void Fighter::checkAttack(Fighter& b)
{
	if (attackCollisionBox.intersects(b.))
}
