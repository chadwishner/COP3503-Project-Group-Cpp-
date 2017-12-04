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
                    std::string name;
                    std::string inventory[5];
                    virtual int die() = 0;
                    virtual std::string getType() {return "Entity";};

	public:         Entity(int h, int mh, int s, int d, int a, int e, int me,           std::string n);
                    virtual int getHP();
                    virtual int getStr();
                    virtual int getDef();
                    virtual int getSta();
                    virtual std::string getName();
                    virtual int takeDamage(int d);
                    virtual int attack(Entity * e);
                    virtual void displayStatus();
};
#endif /* entity_hpp */
