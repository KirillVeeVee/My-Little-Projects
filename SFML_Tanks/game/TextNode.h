//
// Created by kayvee on 19.03.23.
//

#ifndef SFML_TANKS_TEXTNODE_H
#define SFML_TANKS_TEXTNODE_H


#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "SceneNode.h"
#include "Utility.h"

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>


class TextNode : public SceneNode
{
public:
    explicit TextNode(const FontHolder& fonts, const std::string& text);

    void setString(const std::string& text);


private:
    void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;


private:
    sf::Text mText;
};

#endif //SFML_TANKS_TEXTNODE_H
