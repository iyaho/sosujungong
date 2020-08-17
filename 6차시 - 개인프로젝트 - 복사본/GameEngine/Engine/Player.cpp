#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	isJump = false;
	right = false;
	left = false;
	gravity = 9.8f;
	angle = 0.0f;

	playerAnimation = new Animation(10);
	playerAnimation->AddFrame("Resources/Player2.png");
	playerAnimation->AddFrame("Resources/Player3.png");

	AddChild(playerAnimation);

	rect = playerAnimation->getRect();

	setScalingCenter(playerAnimation->getWidth() / 4, playerAnimation->getWidth() / 2);
	playerAnimation->setScale(0.5, 0.5);

	setPos(20, 100);
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

	PlayerUpdate(dTime);





	playerAnimation->Update(dTime);
}

void Player::PlayerUpdate(float dTime)
{
	if (isJump) {
		setPos(getPosX(), getPosY() - 500 * dTime);
	}

	if (left) {
		if (this->getPosX() > 50)
			setPos(getPosX() - 200 * dTime, getPosY());
	}

	if (inputManager->GetKeyState('A') == KEY_DOWN || inputManager->GetKeyState(VK_LEFT) == KEY_DOWN) {
		left = true;
	}

	if (inputManager->GetKeyState('A') == KEY_UP || inputManager->GetKeyState(VK_LEFT) == KEY_UP) {
		left = false;
	}

	if (right) {
		setPos(getPosX() + 250 * dTime, getPosY());
	}

	if (inputManager->GetKeyState('D') == KEY_DOWN || inputManager->GetKeyState(VK_RIGHT) == KEY_DOWN) {
		right = true;
	}

	if (inputManager->GetKeyState('D') == KEY_UP || inputManager->GetKeyState(VK_RIGHT) == KEY_UP) {
		right = false;
	}

	if (inputManager->GetMousePos().x > rect.left) {
		playerAnimation->setScale(0.5, 0.5);
	}
	if (inputManager->GetMousePos().x < rect.right) {
		playerAnimation->setScale(-0.5, 0.5);
	}

	if (getPosY() > 400) {
		setPos(getPosX(), 400);
		isJump = false;
	}

	if (inputManager->GetKeyState('W') == KEY_DOWN || inputManager->GetKeyState(VK_UP) == KEY_DOWN) {
		if (getPosY() == 400) {
			isJump = true;
			gravity = 0;
		}
	}

	if (inputManager->GetKeyState(VK_LBUTTON) == KEY_DOWN) {

	}
	else if (inputManager->GetKeyState(VK_RBUTTON) == KEY_DOWN) {

	}
}