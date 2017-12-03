//  monster.cpp
//  COP3503 Project Group

//  Copyright © 2017 Group 35. All rights reserved.

#include "monster.hpp"

Monster::Monster(int h, int mh, int s, int d, int a, int e, std::string n) : Entity(h, mh, s, d, a, e, n), hp(h), maxhp(mh), str(s), def(d), sta(a), exp(e), name(n){}

int Monster::die(){
    std::cout << "Congratulations! You have slain " << name << "!\n";
    std::cout << "You gained " << exp << " experience points!\n";
    return exp;
}

std::string Monster::getType(){
    return "Monster";
}
