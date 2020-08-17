#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	isJump = false;
	right = false;
	left = false;
	gravity = 9.8f;

	playerAnimation = new Animation(10);
	playerAnimation->AddFrame("Resources/Player2.png");
	playerAnimation->AddFrame("Resources/Player3.png");

	AddChild(playerAnimation);

	rect = playerAnimation->getRect();
}

Player::~Player()
{
	
}

void Player::Render()
{
	Object::Render();
	playerAnimation->Render();
}

void Player::Update(float dTime)
{
	gravity += 9.8f;



	gravity += 9.8f;

	setPos(getPosX(), getPosY() + gravity * dTime);

	if (isJump) {
		setPos(getPosX(), getPosY() - 500 * dTime);
	}

	if (left) {
		setPos(getPosX() - 200 * dTime, getPosY());
		playerAnimation->AddFrame("Resources/Player2.png");
		playerAnimation->AddFrame("Resources/Player3.png");
	}

	if (inputManager->GetKeyState(VK_LEFT) == KEY_DOWN) {
		left = true;
	}

	if (inputManager->GetKeyState(VK_LEFT) == KEY_UP) {
		left = false;
	}

	if (right) {
		setPos(getPosX() + 250 * dTime, getPosY());
	}

	if (inputManager->GetKeyState(VK_RIGHT) == KEY_DOWN) {
		right = true;
	}

	if (inputManager->GetKeyState(VK_RIGHT) == KEY_UP) {
		right = false;
	}


	if (getPosY() > 350) {
		setPos(getPosX(), 350);
		isJump = false;
	}



	if (inputManager->GetKeyState(VK_SPACE) == KEY_DOWN) {
		if (getPosY() == 350) {
			isJump = true;
			gravity = 0;
		}
	}


	playerAnimation->Update(dTime);
}
