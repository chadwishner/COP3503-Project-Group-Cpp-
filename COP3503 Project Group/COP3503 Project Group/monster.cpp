//
//  monster.cpp
//  COP3503 Project Group
//  Copyright © 2017 Group 35. All rights reserved.
//

#include "monster.hpp"
Monster:Entity

string monsters[6] = {"Gator Growl Flyerers","A Seminole", "The Peace Guy", "DM Venmo Requests", "Hurricane Irma", "Segfault"};

int Monster::die()
{
    std::cout << "Congratulations! You have slain " << monsters[roomNum] << "!";
    displayStatus();

}
//what's this for
std::string getType()
{
    return "Monster";
}

void Monster::displayStatus()
{
    std::cout << "HP: " << hp << "/" << maxhp;
    std::cout << "\n";
}

