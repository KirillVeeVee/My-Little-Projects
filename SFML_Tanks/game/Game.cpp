//
// Created by kayvee on 19.03.23.
//

#include "Game.h"
#include <SFML/Window/Event.hpp>


const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game()
        : mWindow(sf::VideoMode(1920, 1080), "World", sf::Style::Close)
        , mWorld(mWindow),mPlayer(mWindow),isPaused(false){
    mWindow.setKeyRepeatEnabled(false);
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (mWindow.isOpen())
    {
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;

            processEvents();
            if(!isPaused) update(TimePerFrame);

        }

        render();
    }
}

void Game::processEvents()
{
    CommandQueue& commands = mWorld.getCommandQueue();

    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        mPlayer.handleEvent(event, commands);

        if (event.type == sf::Event::Closed)
            mWindow.close();
    }

    mPlayer.handleRealtimeInput(commands);
}

void Game::update(sf::Time elapsedTime)
{
    mWorld.update(elapsedTime);
}

void Game::render()
{
    mWindow.clear();
    mWorld.draw();

    mWindow.setView(mWindow.getDefaultView());
    mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key, bool)
{
}