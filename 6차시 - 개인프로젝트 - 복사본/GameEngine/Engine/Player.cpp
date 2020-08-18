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

	potalGun = new Sprite("Resources/potalgun.png");

	AddChild(potalGun);

	rect = playerAnimation->getRect();

	setScalingCenter(playerAnimation->getWidth() / 2, playerAnimation->getWidth() / 2);
	playerAnimation->setScale(1, 1);
	setScalingCenter(potalGun->getWidth() / 2, potalGun->getWidth() / 2);
	potalGun->setScale(1.5, 1.5);

	setPos(20, 100);
	

	setRotationCenter(potalGun->getWidth() / 2, potalGun->getWidth() / 2);
}

Player::~Player()
{
	
}

void Player::Render()
{
	Object::Render();
	playerAnimation->Render();
	potalGun->Render();
}

void Player::Update(float dTime)
{
	gravity += 9.8f;

	gravity += 9.8f;

	setPos(getPosX(), getPosY() + gravity * dTime);

	PlayerUpdate(dTime);

	GetAngle();

	potalGun->setRotation(angle/180/M_PI);

	


	playerAnimation->Update(dTime);
	potalGun->Update(dTime);
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
	if (inputManager->GetMousePos().x > this->getPosX()) {
		playerAnimation->setScale(1, 1);
		potalGun->setPos(playerAnimation->getPosX() + 15, playerAnimation->getPosY() + 22);
		potalGun->setScale(1.5, 1.5);
	}
	if (inputManager->GetMousePos().x < this->getPosX()) {
		playerAnimation->setScale(-1, 1);
		potalGun->setPos(playerAnimation->getPosX() - 15, playerAnimation->getPosY() + 22);
		potalGun->setScale(-1.5, 1.5);
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

void Player::GetAngle()
{
	float Width = fabs(potalGun->getPosX()-inputManager->GetMousePos().x);
	float Height = fabs(potalGun->getPosY() - inputManager->GetMousePos().y);

	angle = atan2(Height, Width);
	conprint(angle);
}
