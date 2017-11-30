//
//  walk_challenge.hpp
//  COP3503 Project Group
//
//  Created by Chad Wishner on 11/5/17.
//  Copyright © 2017 Group 35. All rights reserved.
//

#ifndef walk_challenge_hpp
#define walk_challenge_hpp

#include <string>
#include "challenge.hpp"

using namespace std;

class walkChallenge : public challenge{
	private:		int itemXcor;
					int itemYcor;
					int playerXcor = 0;
					int playerYcor = 0;
	public:			walkChallenge(string item, int xcor, int ycor);
					string win();
					void go();
					int getItemXcor();
					int getItemYcor();
					int getPlayerXcor();
					int getPlayerYcor();
					void movePlayerXcor(int move);
					void movePlayerYcor(int move);
};



#endif /* walk_challenge_hpp */
