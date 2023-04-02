//
// Created by kayvee on 19.03.23.
//

#include "TextNode.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <cmath>


TextNode::TextNode(const FontHolder& fonts, const std::string& text)
{
    mText.setFont(fonts.get(FontsID::Main));
    mText.setCharacterSize(40);
    setString(text);
}

void TextNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mText, states);
}

void TextNode::setString(const std::string& text)
{
    mText.setString(text);
    centerOrigin(mText);
}