//  player.cpp
//  COP3503 Project Group

//  Copyright © 2017 Group 35. All rights reserved.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.hpp"

/* @Parameters Health, Max Health, Strength, Defence, Stamina, Level, Max EXP, name
 */
Player::Player(std::string n) : Entity(30, 30, 20, 10, 10, 0, 30, 1, n), hp(20), maxhp(20), str(10), def(10), sta(10), exp(0), level(1), maxexp(30), name(n){
    for (int i = 0; i < 5; i++) {
        inventory[i] = "None";
    }
}

int Player::die(){
    std::cout << "Alas, brave warrior, you are slain! Expect another semester of COP 3502 in your future.\n";
    std::cout << "Your stats were:\n";
    displayStatus();
    exit(0);
    return 0;
}

std::string Player::getType(){
    return "Player"; // Necessary for certain Entity functions.
}

void Player::heal(int h){
    hp += h;
    if (hp > maxhp) hp = maxhp;
}

std::string * Player::getInv(){
    return inventory;
}
