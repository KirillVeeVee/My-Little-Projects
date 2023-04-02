//
// Created by kayvee on 18.03.23.
//

#include "World.h"
#include "TankTurretEntity.h"

namespace
{
    const std::vector<TankData> Table = initializeTankData();
}

World::World(sf::RenderWindow& window)
        : mWindow(window)
        , mTextures()
        , mFonts()
        , mWorldView(window.getDefaultView())
        , mSceneGraph()
        , mSceneLayers()
        , mWorldBounds(0.f, 0.f, mWorldView.getSize().x, mWorldView.getSize().y)
        , mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldView.getSize().y / 2.f)
        , mPlayerTank(nullptr)
{
    loadTextures();
    loadFonts();
    buildScene();
    mWorldView.setCenter(mSpawnPosition);
}

void World::update(sf::Time dt)
{

    while (!mCommandQueue.isEmpty())
        mSceneGraph.onCommand(mCommandQueue.pop(), dt);
    mSceneGraph.update(dt);

    adaptPlayerPosition();
    adaptEnemyTurret();
    adaptEnemyMovement();
}


void World::draw()
{
    mWindow.setView(mWorldView);
    mWindow.draw(mSceneGraph);
}

void World::loadTextures()
{
    mTextures.load(TexturesID::TURRET_1, "resources/Tank_turret.png");
    mTextures.load(TexturesID::HULL_1, "resources/Tank_hull.png");
    mTextures.load(TexturesID::TERRAIN, "resources/Dirt.jpg");
    mTextures.load(TexturesID::BULLET,"resources/Shell.png");
}

void World::buildScene() {
    for (std::size_t i = 0; i < LayerCount; ++i)
    {
        SceneNode::Ptr layer(new SceneNode());
        mSceneLayers[i] = layer.get();

        mSceneGraph.attachChild(std::move(layer));
    }

    sf::Texture& texture = mTextures.get(TexturesID::TERRAIN);
    sf::IntRect textureRect(mWorldBounds);
    texture.setSmooth(true);
    texture.setRepeated(true);

    std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture, textureRect));
    backgroundSprite->setPosition(mWorldBounds.left, mWorldBounds.top);
    mSceneLayers[Background]->attachChild(std::move(backgroundSprite));

    std::unique_ptr<TankEntity> tank(new TankEntity(TankEntity::Tank1,mFonts));
    mPlayerTank = tank.get();
    mPlayerTank->addHull(TankHullEntity::Type::HULL_1,mTextures);
    mPlayerTank->addTurret(TankTurretEntity::Type::TURRET_1,mTextures);
    mPlayerTank->setPosition(mSpawnPosition);
    mSceneLayers[BattleField]->attachChild(std::move(tank));

    std::unique_ptr<TankEntity> enemyTank(new TankEntity(TankEntity::Enemy_Tank1,mFonts));
    mEnemyTank = enemyTank.get();
    mEnemyTank->addHull(TankHullEntity::Type::HULL_1,mTextures);
    mEnemyTank->addTurret(TankTurretEntity::Type::TURRET_1,mTextures);
    mEnemyTank->setPosition(mWorldBounds.left+150.f,mWorldBounds.height/2-100.f);
    mEnemyTank->rotateHull(180.f);
    mSceneLayers[BattleField]->attachChild(std::move(enemyTank));

}

CommandQueue &World::getCommandQueue() {
    return mCommandQueue;
}

void World::adaptPlayerPosition() {
    {
        sf::FloatRect viewBounds(mWorldView.getCenter() - mWorldView.getSize() / 2.f, mWorldView.getSize());
        const float borderDistance = 70.f;

        sf::Vector2f position = mPlayerTank->getPosition();
        position.x = std::max(position.x, viewBounds.left + borderDistance);
        position.x = std::min(position.x, viewBounds.left + viewBounds.width - borderDistance);
        position.y = std::max(position.y, viewBounds.top + borderDistance);
        position.y = std::min(position.y, viewBounds.top + viewBounds.height - borderDistance);
        mPlayerTank->setPosition(position);
    }

}

void World::loadFonts() {
    mFonts.load(FontsID::Main, 	"resources/Amatic-Bold.ttf");
}

void World::adaptEnemyTurret() {
    auto playerPos=mPlayerTank->getPosition();
    auto enemyPos=mEnemyTank->getPosition();

    float rotation = (atan2(playerPos.y-enemyPos.y, playerPos.x-enemyPos.x)) * 180 / 3.14;

    mEnemyTank->setTurretRotation(rotation);
}

void World::adaptEnemyMovement() {

}
