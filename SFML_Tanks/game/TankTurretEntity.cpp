//
// Created by kayvee on 18.03.23.
//

#include "TankTurretEntity.h"


void TankTurretEntity::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(turretSprite,states);
}

TankTurretEntity::TankTurretEntity(TankTurretEntity::Type _type, TankTurretEntity::TextureHolder &textures)
    :Entity(0)
    ,type(_type)
    ,turretSprite(textures.get(toTextureID(type)))
{

    turretSprite.setScale(XSCALE,YSCALE);
    sf::FloatRect bounds = turretSprite.getLocalBounds();
    turretSprite.setOrigin(bounds.width / 4.f * 3.f, bounds.height / 2.f);

    direction=turretSprite.getOrigin();
    direction.x-=1.f;

}

TexturesID TankTurretEntity::toTextureID(TankTurretEntity::Type _type) {
    switch(_type){
        case Type::TURRET_1: {
            return TexturesID::TURRET_1;
            break;
        }
    }
}

void TankTurretEntity::rotateTurret(float angle) {
    transform.rotate(angle);
    direction=transform*direction;
    rotate(angle);
}

unsigned int TankTurretEntity::getCategory() const {
    return TurretEntity;
}

sf::Vector2f TankTurretEntity::getDirection() const {
    return direction;
}

sf::Sprite& TankTurretEntity::getSprite() {
    return turretSprite;
}

