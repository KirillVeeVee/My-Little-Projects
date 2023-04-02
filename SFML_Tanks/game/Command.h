//
// Created by kayvee on 19.03.23.
//

#ifndef SFML_TANKS_COMMAND_H
#define SFML_TANKS_COMMAND_H

#include "ResourceIdentifiers.h"

#include <SFML/System/Time.hpp>

#include <functional>
#include <cassert>


class SceneNode;

struct Command
{
    Command();
    std::function<void(SceneNode&, sf::Time)>	action;
    unsigned int category;
};

template <typename GameObject, typename Function>
std::function<void(SceneNode&, sf::Time)> derivedAction(Function fn)
{
    return [=] (SceneNode& node, sf::Time dt)
    {
        assert(dynamic_cast<GameObject*>(&node) != nullptr);

        fn(static_cast<GameObject&>(node), dt);
    };
}


#endif //SFML_TANKS_COMMAND_H
