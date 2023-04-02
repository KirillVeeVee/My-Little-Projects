//
// Created by kayvee on 18.03.23.
//

#include "TankHullEntity.h"


TankHullEntity::TankHullEntity(Type _type,TextureHolder& textures)
    :Entity(0)
    ,type(_type)
    ,hullSprite(textures.get(toTextureID(type)))
{

    hullSprite.setScale(XSCALE,YSCALE);
    sf::FloatRect bounds = hullSprite.getLocalBounds();
    hullSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);

    switch (type) {

        case Type::HULL_1:
            break;
    }

}

void TankHullEntity::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(hullSprite,states);
}

TexturesID TankHullEntity::toTextureID(TankHullEntity::Type _type) {
    switch(_type){
        case Type::HULL_1: {
            return TexturesID::HULL_1;
            break;
        }
    }
}

unsigned int TankHullEntity::getCategory() const {
    return HullEntity;
}


void TankHullEntity::rotateHull(float angle) {
    rotate(angle);
}

sf::Sprite &TankHullEntity::getSprite() {
    return hullSprite;
}
