//
// Created by kayvee on 19.03.23.
//

#ifndef SFML_TANKS_ENTITYDATA_H
#define SFML_TANKS_ENTITYDATA_H

#include "ResourceIdentifiers.h"
#include "TankEntity.h"

struct TankHullData{
    int hitpoints;
    float forwardSpeed;
    float reverseSpeed;
    float turnSpeed;
    TexturesID texture;
};

struct TankTurretData{
    float turnSpeed;
    TexturesID texture;
};

struct TankData{
    TankHullData tankHull;
    TankTurretData tankTurret;
};

struct ProjectileData
{
    int								damage;
    float							speed;
    TexturesID					texture;
};

std::vector<TankData> initializeTankData();

std::vector<ProjectileData>	initializeProjectileData();


#endif //SFML_TANKS_ENTITYDATA_H
