//
// Created by kayvee on 19.03.23.
//

#include "TankEntity.h"

namespace
{
    const std::vector<TankData> Table = initializeTankData();
}

unsigned int TankEntity::getCategory() const {
    switch (type){
        case Tank1:
            return CategoryID::PlayerTank;
            break;
        case Enemy_Tank1:
            return CategoryID::EnemyTank;
            break;
    }
}


void TankEntity::accelerate(sf::Vector2f velocity) {
    sf::Transform transform;
    transform.rotate(tankHull->getRotation());
    transform.translate(velocity);
    move(transform*sf::Vector2f());
}

void TankEntity::rotateHull(float angle) {
    tankHull->rotateHull(angle);
}

void TankEntity::rotateTurret(float angle) {
    tankTurret->rotateTurret(angle);
}

void TankEntity::addHull(TankHullEntity::Type _hullType, TextureHolder& textures) {
    std::unique_ptr<TankHullEntity> hull(new TankHullEntity(TankHullEntity::Type::HULL_1, textures));
    hull->setPosition(this->getPosition());
    tankHull = hull.get();
    if(type==Enemy_Tank1) tankHull->getSprite().setColor({255,0,0});
    this->attachChild(std::move(hull));
}

void TankEntity::addTurret(TankTurretEntity::Type _turretType, TextureHolder &textures) {
    std::unique_ptr<TankTurretEntity> turret(new TankTurretEntity(TankTurretEntity::Type::TURRET_1, textures));
    turret->setPosition(getOrigin());
    tankTurret=turret.get();
    if(type==Enemy_Tank1) tankTurret->getSprite().setColor({255,0,0});
    tankHull->attachChild(std::move(turret));
}

TankEntity::TankEntity(TankEntity::Type _type,const FontHolder& fonts)
    :Entity(Table[_type].tankHull.hitpoints)
    ,type(_type),tankHull(nullptr)
    ,tankTurret(nullptr)
{
    std::unique_ptr<TextNode> healthDisplay(new TextNode(fonts, ""));
    mHealthDisplay = healthDisplay.get();
    attachChild(std::move(healthDisplay));
}

void TankEntity::updateText() {
    mHealthDisplay->setString(toString(getHitpoints()) + " HP");
    mHealthDisplay->setPosition(0.f, 100.f);
    mHealthDisplay->setRotation(-getRotation());
}

void TankEntity::updateCurrent(sf::Time dt) {
    updateText();
}

float TankEntity::getForwardSpeed() const {
    return Table[type].tankHull.forwardSpeed;
}

float TankEntity::getReversSpeed() const {
    return Table[type].tankHull.reverseSpeed;
}

float TankEntity::getRotateSpeed() const {
    return Table[type].tankHull.turnSpeed;

}

float TankEntity::getTurretRotateSpeed() const {
    return Table[type].tankTurret.turnSpeed;
}

void TankEntity::setTurretRotation(float angle) {
    tankTurret->setRotation(angle);
}

void TankEntity::fire() {

}

