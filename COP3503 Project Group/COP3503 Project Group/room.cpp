//
//  room.cpp
//  COP3503 Project Group
//
//  Created by Chad Wishner on 11/5/17.
//  Copyright © 2017 Group 35. All rights reserved.
//

#include "room.hpp"
#include "challenge.hpp"

Room::Room(challenge c, std::string message, std::vector<std::string> choices){
    this->message = message;
    this->complete = false;
}

std::string Room::getMessage(){
    return message;
}

std::vector<std::string> Room::getChoices(){
    return choices;
}

bool Room::isComplete(){
    return complete;
}

