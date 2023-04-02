//
// Created by kayvee on 19.03.23.
//

#ifndef SFML_TANKS_TANKENTITY_H
#define SFML_TANKS_TANKENTITY_H
#include "Entity.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "TankHullEntity.h"
#include "TankTurretEntity.h"
#include "EntityData.h"
#include "TextNode.h"
#include "Utility.h"
#include "CommandQueue.h"

class TankEntity: public Entity{
public:
    enum Type{Tank1,Enemy_Tank1,TypeCount};

    using TextureHolder = ResourceHolder<sf::Texture,TexturesID> ;

    explicit TankEntity(Type _type, const FontHolder& fonts);

    unsigned int getCategory() const override;

    void addHull(TankHullEntity::Type _hullType, TextureHolder& textures);

    void addTurret(TankTurretEntity::Type _turretType, TextureHolder& textures);

    void accelerate(sf::Vector2f velocity);

    void rotateHull(float angle);

    void rotateTurret(float angle);

    void setTurretRotation(float angle);

    void updateText();

    float getForwardSpeed() const;

    void fire();

    float getReversSpeed() const;

    float getRotateSpeed() const;

    float getTurretRotateSpeed() const;

private:
    void updateCurrent(sf::Time dt) override;
private:
    Type type;
    TankHullEntity* tankHull;
    TankTurretEntity* tankTurret;
    TextNode* mHealthDisplay;
};


#endif //SFML_TANKS_TANKENTITY_H
