#pragma once
#define _USE_MATH_DEFINES
#include "Object.h"
#include "Sprite.h"
#include "Animation.h"
#include <math.h>
#include <cmath>


class Player :
    public Object
{
private:
    Animation* playerAnimation;
    Sprite* potalGun;
    float gravity;
    bool isJump;
    bool left, right;
public:
    Player();
    ~Player();

    bool bt, ot;
    float angle;
    void Render();
    void Update(float dTime);

    void PlayerUpdate(float dTime);

    void GetAngle();
};

