//
// Created by kayvee on 18.03.23.
//

#ifndef SFML_TANKS_TANKHULLENTITY_H
#define SFML_TANKS_TANKHULLENTITY_H

#include "Entity.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"

class TankHullEntity: public Entity {
public:
    enum Type{HULL_1,TypeCount};

    using TextureHolder = ResourceHolder<sf::Texture,TexturesID> ;

    explicit TankHullEntity(Type type,TextureHolder& textures);

    void drawCurrent(sf::RenderTarget& target,
                sf::RenderStates states) const override;

    static TexturesID toTextureID(Type _type);

    unsigned int getCategory() const override;


    void rotateHull(float angle);

    sf::Sprite& getSprite();

private:
    Type type;
    sf::Sprite hullSprite;
    const float XSCALE=0.35f,YSCALE=0.35f;

};


#endif //SFML_TANKS_TANKHULLENTITY_H
