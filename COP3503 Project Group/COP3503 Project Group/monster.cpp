//  monster.cpp
//  COP3503 Project Group

//  Copyright © 2017 Group 35. All rights reserved.

#include "monster.hpp"

Monster::Monster(int h, int mh, int s, int d, int a, int e, int me, int lvl, std::string n) : Entity(h, mh, s, d, a, e, me, lvl, n), hp(h), maxhp(mh), str(s), def(d), sta(a), exp(e), level(lvl), maxexp(0), name(n){
}

int Monster::die(){
    std::cout << "Congratulations! You have slain " << name << "!\n";
    std::cout << "You gained " << exp << " experience points!\n";
    return exp; // It'll be a long journey before this reaches the player object.
}

std::string Monster::getType(){
    return "Monster";
}
