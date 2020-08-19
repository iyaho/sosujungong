#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	isJump = false;
	isGravity = true;
	right = false;
	left = false;
	gravity = 9.8f;
	angle = 0.0f;
	bt = false;
	ot = false;

	playerAnimation = new Animation(10);
	playerAnimation->AddFrame("Resources/Player2.png");
	playerAnimation->AddFrame("Resources/Player3.png");

	AddChild(playerAnimation);

	potalGun = new Sprite("Resources/potalgun.png");

	AddChild(potalGun);

	rect = playerAnimation->getRect();

	setScalingCenter(playerAnimation->getWidth(), playerAnimation->getHeight());
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
	if (isGravity)
	{
		gravity += 9.8f;
		gravity += 9.8f;
	}
	else
	{
		gravity = 0;
	}

	setPos(getPosX(), getPosY() + gravity * dTime);

	PlayerUpdate(dTime);

	potalGun->setRotation(angle);


	


	playerAnimation->Update(dTime);
	potalGun->Update(dTime);
}

void Player::PlayerUpdate(float dTime)
{
	if (getPosY() > 400) {
		isGravity = true;
	}
	conprint(gravity);
	if (isJump) {
		setPos(getPosX(), getPosY() - 500 * dTime);
		isGravity = true;
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
		if (this->getPosX() < 950)
			setPos(getPosX() + 250 * dTime, getPosY());
	}

	if (inputManager->GetKeyState('D') == KEY_DOWN || inputManager->GetKeyState(VK_RIGHT) == KEY_DOWN) {
		right = true;
	}

	if (inputManager->GetKeyState('D') == KEY_UP || inputManager->GetKeyState(VK_RIGHT) == KEY_UP) {
		right = false;
	}

	GetAngle();
	if (inputManager->GetMousePos().x > this->getPosX()) {
		playerAnimation->setScale(1, 1);
		potalGun->setPos(playerAnimation->getPosX() + 15, playerAnimation->getPosY() + 22);
		potalGun->setScale(1.5, 1.5);
	}
	if (inputManager->GetMousePos().x < this->getPosX()) {
		playerAnimation->setScale(-1, 1);
		potalGun->setPos(playerAnimation->getPosX() - 15, playerAnimation->getPosY() + 22);
		potalGun->setScale(-1.5, 1.5);
		angle += M_PI;
	}

	if (getPosY() > 400) {
		setPos(getPosX(), 400);
		isJump = false;
		gravity = 0;
	}

	if (inputManager->GetKeyState('W') == KEY_DOWN || inputManager->GetKeyState(VK_UP) == KEY_DOWN) {
		if (getPosY() >= 400) {
			isJump = true;
			gravity = 0;
		}
	}
	
	
}

void Player::GetAngle()
{
	angle = atan2f( ( inputManager->GetMousePos().y - getPosY() ), ( inputManager->GetMousePos().x - getPosX() ) );
}
