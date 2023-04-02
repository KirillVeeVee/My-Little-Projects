//
// Created by kayvee on 18.03.23.
//

#ifndef SFML_TANKS_WORLD_H
#define SFML_TANKS_WORLD_H

#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "SceneNode.h"
#include "SpriteNode.h"
#include "TankEntity.h"
#include "CommandQueue.h"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <array>
#include <cmath>


// Forward declaration
namespace sf
{
    class RenderWindow;
}

class World : private sf::NonCopyable
{
public:

    explicit World(sf::RenderWindow& window);

    void update(sf::Time dt);

    void draw();

    CommandQueue& getCommandQueue();

    void adaptPlayerPosition();

    void adaptEnemyTurret();

    void adaptEnemyMovement();

private:
    void loadTextures();

    void loadFonts();

    void buildScene();


private:
    enum Layer
    {
        Background,
        BattleField,
        LayerCount
    };


private:
    sf::RenderWindow& mWindow;
    TextureHolder mTextures;
    FontHolder	mFonts;

    SceneNode mSceneGraph;
    std::array<SceneNode*, LayerCount>	mSceneLayers;

    sf::View mWorldView;
    sf::FloatRect mWorldBounds;

    sf::Vector2f mSpawnPosition;
    TankEntity* mPlayerTank;
    TankEntity* mEnemyTank;

    CommandQueue mCommandQueue;

};

#endif //SFML_TANKS_WORLD_H
