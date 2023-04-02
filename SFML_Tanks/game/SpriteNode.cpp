//
// Created by kayvee on 18.03.23.
//

#include "SpriteNode.h"

SpriteNode::SpriteNode(const sf::Texture &texture):mSprite(texture) {

}

SpriteNode::SpriteNode(const sf::Texture &texture, const sf::IntRect &rect):mSprite(texture,rect) {

}

void SpriteNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mSprite,states);
}

const sf::Sprite &SpriteNode::getSprite() const {
    return mSprite;
}

sf::Sprite &SpriteNode::getSprite() {
    return mSprite;
}
