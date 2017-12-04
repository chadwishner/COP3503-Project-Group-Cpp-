//  player.hpp
//  COP3503 Project Group

//  Copyright © 2017 Group 35. All rights reserved.

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include <string>
#include "entity.hpp"

class Player: public Entity{
	private:        int hp;
                    int maxhp;
                    int str;
                    int def;
                    int sta;
                    int exp;
                    int level;
                    int maxexp;
                    std::string name;
                    std::string inventory[5];
                    //void levelUp();
                    int die() override;
                    std::string getType() override;
	public:         Player(std::string n);
                    void heal(int h);
                    //void gainExp(int e);
                    std::string * getInv();
                    //void displayStatus();
};

#endif /* player_hpp */
