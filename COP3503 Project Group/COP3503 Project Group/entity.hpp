//  entity.hpp
//  COP3503 Project Group

//  Copyright © 2017 Group 35. All rights reserved.

#ifndef entity_hpp
#define entity_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <cmath>

class Entity
{
	protected:      int hp;
                    int maxhp;
                    int str;
                    int def;
                    int sta;
                    int exp;
                    int maxexp;
                    int level;
                    std::string name;
                    std::string inventory[5];
                    virtual void levelUp();
                    virtual int die() = 0;
                    virtual std::string getType() {return "Entity";};

	public:         Entity(int h, int mh, int s, int d, int a, int e, int me, int lvl, std::string n);
                    virtual int getHP();
                    virtual int getStr();
                    virtual int getDef();
                    virtual int getSta();
                    virtual std::string getName();
                    virtual int takeDamage(int d);
                    virtual int attack(Entity * e);
                    virtual void displayStatus();
                    virtual void gainExp(int e);
};
#endif /* entity_hpp */
