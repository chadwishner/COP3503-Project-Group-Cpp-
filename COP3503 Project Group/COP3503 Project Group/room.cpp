//
//  room.cpp
//  COP3503 Project Group
//
//  Created by Chad Wishner on 11/5/17.
//  Copyright © 2017 Group 35. All rights reserved.
//

#include "room.hpp"
#include "challenge.hpp"

Room::Room(challenge *c, std::string message, std::string flavorText, std::vector<std::string> choices){
    this->ch = c;
    this->message = message;
    this->flavorText = flavorText;
    this->choices = choices;
    this->complete = false;
}

std::string Room::getMessage(){
    return message;
}

std::vector<std::string> Room::getChoices(){
    return choices;
}

std::string Room::getFlavorText(){
    return flavorText;
}

Monster * Room::getMonster(){
    return m;
}

challenge * Room::getChallenge(){
    return ch;
}

void Room::setComplete(){
    this->complete = false;
}

bool Room::isComplete(){
    return complete;
}
