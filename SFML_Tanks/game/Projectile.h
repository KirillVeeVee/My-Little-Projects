//
// Created by kayvee on 20.03.23.
//

#ifndef SFML_TANKS_PROJECTILE_H
#define SFML_TANKS_PROJECTILE_H


#include "Entity.h"
#include "ResourceIdentifiers.h"
#include "CommandQueue.h"

#include <SFML/Graphics/Sprite.hpp>


class Projectile : public Entity
{
public:
    enum Type
    {
        AlliedBullet,
        EnemyBullet,
        Missile,
        TypeCount
    };


public:
    Projectile(Type type, const TextureHolder& textures);

    void guideTowards(sf::Vector2f position);
    bool isGuided() const;

    virtual unsigned int getCategory() const;
    virtual sf::FloatRect getBoundingRect() const;
    float getMaxSpeed() const;
    int getDamage() const;


private:
    virtual void updateCurrent(sf::Time dt, CommandQueue& commands);
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;


private:
    Type					mType;
    sf::Sprite				mSprite;
    sf::Vector2f			mTargetDirection;
};


#endif //SFML_TANKS_PROJECTILE_H
