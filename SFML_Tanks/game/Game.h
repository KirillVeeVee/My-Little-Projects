//
// Created by kayvee on 19.03.23.
//


#ifndef BOOK_GAME_HPP
#define BOOK_GAME_HPP

#include "World.h"
#include "Player.h"

#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class Game : private sf::NonCopyable
{
public:
    Game();
    void run();


private:
    void processEvents();
    void update(sf::Time elapsedTime);
    void render();

    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);


private:
    static const sf::Time	TimePerFrame;

    sf::RenderWindow		mWindow;
    World					mWorld;
    Player					mPlayer;

    bool isPaused;
};

#endif // BOOK_GAME_HPP