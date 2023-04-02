//
// Created by kayvee on 18.03.23.
//

#ifndef SFML_TANKS_ENTITY_H
#define SFML_TANKS_ENTITY_H
#include <SFML/Graphics.hpp>
#include "SceneNode.h"

class Entity: public SceneNode {
public:

    explicit Entity(int _hitpoints);

    void setVelocity(sf::Vector2f _velocity);

    void setVelocity(float vx,float vy);

    sf::Vector2f getVelocity() const;

    void repair(int hitpoints);

    void damage(int hitpoints);

    void destroy();

    int getHitpoints() const;

    bool isDestroyed() const;

protected:
    void updateCurrent(sf::Time dt) override;

private:
    sf::Vector2f velocity;
    int eHitpoints;
};


#endif //SFML_TANKS_ENTITY_H
