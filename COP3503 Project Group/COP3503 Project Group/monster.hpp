//
//  monster.hpp
//  COP3503 Project Group
//  Copyright © 2017 Group 35. All rights reserved.
//

#ifndef monster_hpp
#define monster_hpp

#include <stdio.h>
#include <iostream>
#include "entity.hpp"

// Framework for Monster class, needs to be finalized

class Monster : public Entity{
private:
    int hp;
    int maxhp;
public:
    std::string getType();
    void displayStatus();
    int die(); // Not sure why this returns an int, needs clarification
};

#endif /* monster_hpp */
