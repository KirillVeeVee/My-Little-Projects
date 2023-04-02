//
// Created by kayvee on 18.03.23.
//

#ifndef SFML_TANKS_TANKTURRETENTITY_H
#define SFML_TANKS_TANKTURRETENTITY_H

#include "Entity.h"
#include "ResourceIdentifiers.h"
#include "ResourceHolder.h"
#include <SFML/Graphics.hpp>


class TankTurretEntity : public Entity{
public:
    enum Type{TURRET_1,TypeCount};

    using TextureHolder = ResourceHolder<sf::Texture,TexturesID> ;

    explicit TankTurretEntity(Type type, TextureHolder& textures);

    void drawCurrent(sf::RenderTarget& target,
                     sf::RenderStates states) const override;

    static TexturesID toTextureID(Type _type);

    void rotateTurret(float angle);

    unsigned int getCategory() const override;

    sf::Vector2f getDirection() const;

    sf::Sprite& getSprite();
private:
    Type type;
    sf::Transform transform;
    sf::Sprite turretSprite;
    const float XSCALE=0.35f,YSCALE=0.35f;

    sf::Vector2f direction;
};


#endif //SFML_TANKS_TANKTURRETENTITY_H
