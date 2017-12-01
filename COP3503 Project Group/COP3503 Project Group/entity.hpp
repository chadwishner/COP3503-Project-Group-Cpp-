//
//  entity.hpp
//  COP3503 Project Group
//
//  Created by Chad Wishner on 11/5/17.
//  Copyright © 2017 Group 35. All rights reserved.
//

#ifndef entity_hpp
#define entity_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <cmath>

class Entity
{
	protected:
		int hp;
		int maxhp;
		int str;
		int def;
		int sta;
		int exp;
		std::string name;
		virtual int die();
		virtual std::string getType();

	public:
		Entity(int h, int mh, int s, int d, int a, int e, std::string n);
		virtual int getHP();
		virtual int getStr();
		virtual int getDef();
		virtual int getSta();
		virtual std::string getName();
		virtual int takeDamage(int d);
		virtual int attack(Entity * e);
};
#endif /* entity_hpp */
