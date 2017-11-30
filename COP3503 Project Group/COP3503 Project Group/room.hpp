//
//  room.hpp
//  COP3503 Project Group
//
//  Created by Chad Wishner on 11/5/17.
//  Copyright © 2017 Group 35. All rights reserved.
//

#ifndef room_hpp
#define room_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "challenge.hpp" // Need to define Challenge superclass

class Room{
private:
    challenge * challenge;
    bool complete; // If true, player can move on to next room
    std::string message; // Flavor text displayed when room is entered
    std::vector<std::string> choices;
public:
    Room(challenge c, std::string message, std::vector<std::string> choices); // Constructor subject to change based on structure of program
    std::string getMessage();
    std::vector<std::string> getChoices();
    bool isComplete();
   
};


#endif /* room_hpp */
