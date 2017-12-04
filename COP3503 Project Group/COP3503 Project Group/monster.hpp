//  monster.hpp
//  COP3503 Project Group

//  Copyright © 2017 Group 35. All rights reserved.

#ifndef monster_hpp
#define monster_hpp

#include <stdio.h>
#include <iostream>
#include "entity.hpp"

class Monster : public Entity{
	private:	int hp;
				int maxhp;
				int str;
				int def;
				int sta;
				int exp;
                int maxexp;
                int level;
                std::string name;

    public:		Monster(int h, int mh, int s, int d, int a, int e, int me, int lvl, std::string n);
				std::string getType() override;
				int die() override;
};

#endif /* monster_hpp */
