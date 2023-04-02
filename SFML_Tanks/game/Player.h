//
// Created by kayvee on 19.03.23.
//

#ifndef SFML_TANKS_PLAYER_H
#define SFML_TANKS_PLAYER_H

#include "Command.h"

#include <SFML/Window/Event.hpp>

#include <map>
#include <cmath>


class CommandQueue;

class Player
{
public:
    enum Action
    {
        TurnLeft,
        TurnRight,
        MoveUp,
        MoveDown,
        TurretLeft,
        TurretRight,
        Fire,
        ActionCount
    };


public:
    Player(sf::Window& _mWindow);

    void handleEvent(const sf::Event& event, CommandQueue& commands);
    void handleRealtimeInput(CommandQueue& commands);

    void assignKey(Action action, sf::Keyboard::Key key);

    sf::Keyboard::Key getAssignedKey(Action action) const;


private:
    void initializeActions();
    static bool isRealtimeAction(Action action);


private:
    sf::Window& mWindow;
    std::map<sf::Keyboard::Key, Action>		mKeyBinding;
    std::map<Action, Command>				mActionBinding;
};


#endif //SFML_TANKS_PLAYER_H
