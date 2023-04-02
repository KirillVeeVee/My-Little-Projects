//
// Created by kayvee on 18.03.23.
//

#ifndef SFML_TANKS_RESOURCEIDENTIFIERS_H
#define SFML_TANKS_RESOURCEIDENTIFIERS_H
#include <SFML/Graphics.hpp>

enum CategoryID
{
    None				= 0,
    Scene				= 1 << 0,
    PlayerTank		    = 1 << 1,
    EnemyTank           = 1 << 2,
    TurretEntity        = 1 << 3,
    HullEntity          = 1 << 4,
    EnemyShell          = 1 << 5,
    PlayerShell          = 1 << 6
};


enum class  TexturesID{
        HULL_1,
        TURRET_1,
        TERRAIN,
        BULLET
    };

enum class FontsID{
    Main
};


template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, TexturesID> TextureHolder;
typedef ResourceHolder<sf::Font, FontsID> FontHolder;


#endif //SFML_TANKS_RESOURCEIDENTIFIERS_H
