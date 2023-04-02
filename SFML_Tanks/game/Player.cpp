//
// Created by kayvee on 19.03.23.
//

#include "Player.h"
#include "CommandQueue.h"
#include "TankEntity.h"

#include <map>
#include <string>
#include <algorithm>


struct TankMoveForward
{
    TankMoveForward(float vx, float vy)
            : velocity(vx, vy)
    {
    }

    void operator() (TankEntity& tank, sf::Time) const
    {
        tank.accelerate(velocity*tank.getForwardSpeed());
    }

    sf::Vector2f velocity;
};

struct TankMoveBackward
{
    TankMoveBackward(float vx, float vy)
            : velocity(vx, vy)
    {
    }

    void operator() (TankEntity& tank, sf::Time) const
    {
        tank.accelerate(velocity*tank.getReversSpeed());
    }

    sf::Vector2f velocity;
};

struct TankHullRotate
{
    explicit TankHullRotate(float _angle):angle(_angle){

    }

    void operator() (TankEntity& tank, sf::Time) const
    {

        tank.rotateHull(angle*tank.getRotateSpeed());
    }

    float angle;
};
struct TankTurretRotate{
    explicit TankTurretRotate(float _angle):angle(_angle){

    }

    void operator() (TankEntity& tankTurret, sf::Time) const
    {

        tankTurret.rotateTurret(angle*tankTurret.getTurretRotateSpeed());
    }

    float angle;
};

Player::Player(sf::Window& _mWindow):mWindow(_mWindow)
{
    mKeyBinding[sf::Keyboard::A] = TurnLeft;
    mKeyBinding[sf::Keyboard::D] = TurnRight;
    mKeyBinding[sf::Keyboard::W] = MoveUp;
    mKeyBinding[sf::Keyboard::S] = MoveDown;
    mKeyBinding[sf::Keyboard::Q] = TurretLeft;
    mKeyBinding[sf::Keyboard::E] = TurretRight;
    mKeyBinding[sf::Keyboard::Space] = Fire;

    initializeActions();

    for(auto& pair:mActionBinding) {
        pair.second.category = CategoryID::PlayerTank;
    }
}

void Player::handleEvent(const sf::Event& event, CommandQueue& commands)
{
    if (event.type == sf::Event::KeyPressed)
    {
        auto found = mKeyBinding.find(event.key.code);
        if (found != mKeyBinding.end() && !isRealtimeAction(found->second))
            commands.push(mActionBinding[found->second]);
    }
}

void Player::handleRealtimeInput(CommandQueue& commands)
{
    for(auto& pair:mKeyBinding)
    {
        if (sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second))
            commands.push(mActionBinding[pair.second]);
    }
}

void Player::assignKey(Action action, sf::Keyboard::Key key)
{
    for (auto itr = mKeyBinding.begin(); itr != mKeyBinding.end(); )
    {
        if (itr->second == action)
            mKeyBinding.erase(itr++);
        else
            ++itr;
    }

    mKeyBinding[key] = action;
}

sf::Keyboard::Key Player::getAssignedKey(Action action) const
{
    for(auto& pair:mKeyBinding)
    {
        if (pair.second == action)
            return pair.first;
    }

    return sf::Keyboard::Unknown;
}

void Player::initializeActions()
{
    mActionBinding[TurnLeft].action	 = derivedAction<TankEntity>(TankHullRotate(-1));
    mActionBinding[TurnRight].action = derivedAction<TankEntity>(TankHullRotate(+1));
    mActionBinding[MoveUp].action    = derivedAction<TankEntity>(TankMoveForward(-1, 0.f ));
    mActionBinding[MoveDown].action  = derivedAction<TankEntity>(TankMoveBackward(+1,0.f ));
    mActionBinding[TurretLeft].action = derivedAction<TankEntity>(TankTurretRotate(-1));
    mActionBinding[TurretRight].action = derivedAction<TankEntity>(TankTurretRotate(+1));
    mActionBinding[Fire].action          = derivedAction<TankEntity>([] (TankEntity& a, sf::Time){ a.fire(); });
}

bool Player::isRealtimeAction(Action action)
{
    switch (action)
    {
        case TurnLeft:
        case TurnRight:
        case MoveDown:
        case MoveUp:
        case TurretLeft:
        case TurretRight:
        case Fire:
            return true;

        default:
            return false;
    }
}