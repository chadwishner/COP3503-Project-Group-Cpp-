//
//  room.cpp
//  COP3503 Project Group
//
//  Created by Chad Wishner on 11/5/17.
//  Copyright © 2017 Group 35. All rights reserved.
//

#include "room.hpp"
#include "challenge.hpp"

Room::Room(std::string message){
    //challenge = new Challenge();
    this->complete = false;
}

std::string Room::getMessage(){
    return message;
}

void Room::printChoices(){
    
}
