//
// Created by kayvee on 19.03.23.
//

#ifndef SFML_TANKS_UTILITY_H
#define SFML_TANKS_UTILITY_H

#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>

#include <sstream>


namespace sf
{
    class Sprite;
    class Text;
}


template <typename T>
std::string toString(const T& value)
{
    std::stringstream stream;
    stream << value;
    return stream.str();
}
std::string toString(sf::Keyboard::Key key);

void centerOrigin(sf::Sprite& sprite);
void centerOrigin(sf::Text& text);

float toDegree(float radian);
float toRadian(float degree);

int randomInt(int exclusiveMax);

float length(sf::Vector2f vector);
sf::Vector2f unitVector(sf::Vector2f vector);


#endif //SFML_TANKS_UTILITY_H
