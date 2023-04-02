//
// Created by kayvee on 18.03.23.
//

#ifndef SFML_TANKS_SPRITENODE_H
#define SFML_TANKS_SPRITENODE_H

#include "SceneNode.h"

class SpriteNode: public SceneNode{
public:
    explicit SpriteNode(const sf::Texture& texture);

    SpriteNode(const sf::Texture& texture,const sf::IntRect& rect);

    const sf::Sprite& getSprite() const;

    sf::Sprite& getSprite();

private:
    void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::Sprite mSprite;
};


#endif //SFML_TANKS_SPRITENODE_H
