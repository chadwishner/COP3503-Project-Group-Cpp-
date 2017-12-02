//  monster.cpp

//  COP3503 Project Group
//  Copyright © 2017 Group 35. All rights reserved.

#include "monster.hpp"

//std::string monsters[6] = {"Gator Growl Flyerers","A Seminole", "The Peace Guy", "DM Venmo Requests", "Hurricane Irma", "Segfault"};

Monster::Monster(int h, int mh, int s, int d, int a, int e, std::string n) : hp(h), maxhp(mh), str(s), def(d), sta(a), exp(e), name(n){}

int Monster::die(){
    std::cout << "Congratulations! You have slain " << name << "!\n";
    std::cout << "You gained " << exp << " experience points!\n";
    return exp;
}

//what's this for
std::string Monster::getType(){
    return "Monster";
}

/*
void Monster::displayStatus()
{
    std::cout << "HP: " << hp << "/" << maxhp;
    std::cout << "\n";
}
*/

