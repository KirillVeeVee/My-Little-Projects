//
// Created by kayvee on 18.03.23.
//

#include "Entity.h"

void Entity::setVelocity(sf::Vector2f _velocity) {
    velocity=_velocity;
}

void Entity::setVelocity(float vx, float vy) {
    velocity.x=vx;
    velocity.y=vy;
}

sf::Vector2f Entity::getVelocity() const {
    return velocity;
}

void Entity::updateCurrent(sf::Time dt) {
    move(velocity * dt.asSeconds());
}

void Entity::repair(int hitpoints) {
    eHitpoints+=hitpoints;
}

void Entity::damage(int hitpoints) {
    eHitpoints-=hitpoints;
}

void Entity::destroy() {
    eHitpoints=0;
}

int Entity::getHitpoints() const {
    return eHitpoints;
}

bool Entity::isDestroyed() const {
    return eHitpoints;
}

Entity::Entity(int _hitpoints) {
    eHitpoints=_hitpoints;
}
