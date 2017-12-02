//  room.hpp
//  COP3503 Project Group

//  Copyright © 2017 Group 35. All rights reserved.

#ifndef room_hpp
#define room_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "challenge.hpp"
#include "monster.hpp"

class Room{
private:
    challenge * ch;
    Monster * monster;
    bool complete; // If true, player can move on to next room
    std::string message; // Displayed when room is entered
    std::string flavorText; // Displayed when "look around" is chosen
    std::vector<std::string> choices; // Choices to be displayed
public:
    Room(challenge *c, Monster *m, std::string message, std::string flavorText, std::vector<std::string> choices);
    std::string getMessage();
    std::string getFlavorText();
    std::vector<std::string> getChoices();
    challenge * getChallenge();
    Monster * getMonster();
    void setComplete();
    bool isComplete();
};

#endif /* room_hpp */
