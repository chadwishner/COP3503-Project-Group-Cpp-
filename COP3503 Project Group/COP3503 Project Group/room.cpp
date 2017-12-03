//  room.cpp
//  COP3503 Project Group

//  Copyright © 2017 Group 35. All rights reserved.

#include "room.hpp"

// Constructor

Room::Room(challenge *c, Monster *m, std::string message, std::string flavorText, std::vector<std::string> choices){
    this->ch = c;
    this->monster = m;
    this->message = message;
    this->flavorText = flavorText;
    this->choices = choices;
    this->complete = false;
}

std::string Room::getMessage(){ // Returns the message to be displayed upon entering room
    return message;
}

std::vector<std::string> Room::getChoices(){ // Returns choices provided to the player as a vector
    return choices;
}

std::string Room::getFlavorText(){ // Returns flavor text to be displayed when "look around" choice is selected
    return flavorText;
}

Monster * Room::getMonster(){ // Returns Monster associated with room
    return monster;
}

challenge * Room::getChallenge(){ // Returns challenge associated with room
    return ch;
}

void Room::setComplete(){ // Set flag "complete" to true
    this->complete = true;
}

bool Room::isComplete(){ // Returns value of "complete"
    return complete;
}
