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
		int getHP();
		int getStr();
		int getDef();
		int getSta();
		std::string getName();
		void takeDamage(int d);
		void attack(Entity * e);
};
#endif /* entity_hpp */
