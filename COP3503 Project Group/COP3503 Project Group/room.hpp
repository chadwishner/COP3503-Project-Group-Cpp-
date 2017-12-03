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
private:        challenge * ch; // Challenge associated with room
                Monster * monster; // Monster associated with room
                bool complete; // If true, player can move on to next room
                std::string message; // Displayed when room is entered
                std::string flavorText; // Displayed when "look around" is chosen
                std::vector<std::string> choices; // Choices to be displayed

public:         Room(challenge *c, Monster *m, std::string message, std::string flavorText, std::vector<std::string> choices); // Constructor
                std::string getMessage(); // Message getter
                std::string getFlavorText(); // Flavor text getter
                std::vector<std::string> getChoices(); // Choices getter
                challenge * getChallenge(); // Challenge getter
                Monster * getMonster(); // Monster getter
                void setComplete(); // Completion flag setter
                bool isComplete(); // Completion flag getter
};

#endif /* room_hpp */
