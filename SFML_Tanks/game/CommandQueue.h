//
// Created by kayvee on 19.03.23.
//

#ifndef SFML_TANKS_COMMANDQUEUE_H
#define SFML_TANKS_COMMANDQUEUE_H

#include "Command.h"

#include <queue>


class CommandQueue
{
public:
    void push(const Command& command);
    Command pop();
    bool isEmpty() const;


private:
    std::queue<Command>			mQueue;
};



#endif //SFML_TANKS_COMMANDQUEUE_H
