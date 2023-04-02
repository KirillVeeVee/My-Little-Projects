//
// Created by kayvee on 19.03.23.
//

#include "EntityData.h"
#include "Projectile.h"

std::vector<TankData> initializeTankData(){
    std::vector<TankData> data(TankEntity::TypeCount);

    data[TankEntity::Tank1].tankHull.hitpoints=1000;
    data[TankEntity::Tank1].tankHull.forwardSpeed=4.f;
    data[TankEntity::Tank1].tankHull.reverseSpeed=2.f;
    data[TankEntity::Tank1].tankHull.turnSpeed=1.f;
    data[TankEntity::Tank1].tankHull.texture=TexturesID::HULL_1;
    data[TankEntity::Tank1].tankTurret.turnSpeed=1.f;
    data[TankEntity::Tank1].tankTurret.texture=TexturesID::HULL_1;

    data[TankEntity::Enemy_Tank1].tankHull.hitpoints=200;
    data[TankEntity::Enemy_Tank1].tankHull.forwardSpeed=3.f;
    data[TankEntity::Enemy_Tank1].tankHull.reverseSpeed=2.f;
    data[TankEntity::Enemy_Tank1].tankHull.turnSpeed=1.f;
    data[TankEntity::Enemy_Tank1].tankHull.texture=TexturesID::HULL_1;
    data[TankEntity::Enemy_Tank1].tankTurret.turnSpeed=1.f;
    data[TankEntity::Enemy_Tank1].tankTurret.texture=TexturesID::HULL_1;

    return data;
}

std::vector<ProjectileData> initializeProjectileData()
{
    std::vector<ProjectileData> data(Projectile::TypeCount);

    data[Projectile::AlliedBullet].damage = 10;
    data[Projectile::AlliedBullet].speed = 300.f;
    data[Projectile::AlliedBullet].texture = TexturesID::BULLET;

    data[Projectile::EnemyBullet].damage = 10;
    data[Projectile::EnemyBullet].speed = 300.f;
    data[Projectile::EnemyBullet].texture = TexturesID::BULLET;

    return data;
}