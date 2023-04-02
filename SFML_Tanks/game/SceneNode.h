//
// Created by kayvee on 18.03.23.
//

#ifndef SFML_TANKS_SCENENODE_H
#define SFML_TANKS_SCENENODE_H
#include <SFML/Graphics.hpp>
#include <memory>
#include <cassert>
#include "ResourceIdentifiers.h"
#include "Command.h"

class SceneNode :  public sf::Transformable, public sf::Drawable,
                   private sf::NonCopyable
{
public:
    using Ptr = std::unique_ptr<SceneNode>;
public:
    SceneNode();

    void attachChild(Ptr child);

    Ptr detachChild(const SceneNode& node);

    void update(sf::Time dt);

    sf::Transform getWorldTransform() const;

    sf::Vector2f getWorldPosition() const;

    virtual unsigned int getCategory() const;

    void onCommand(const Command& command,sf::Time dt);

private:

    virtual void updateCurrent(sf::Time dt);

    void updateChildren(sf::Time dt);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const final;

    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;



private:

    std::vector<Ptr> mChildren;
    SceneNode* mParent;
};


#endif //SFML_TANKS_SCENENODE_H
