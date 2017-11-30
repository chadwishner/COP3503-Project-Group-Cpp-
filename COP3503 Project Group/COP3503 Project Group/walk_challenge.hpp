//  walk_challenge.hpp
//  COP3503 Project Group

//  Copyright © 2017 Group 35. All rights reserved.
//

/*Created walk challenge as a function call, don't see why we need it as an object, could just call 1 of 3 challenge functions in challenge class (challenge class can handle what the item is, and 3 fucntions only have to pass in item and return item when goal is met)
 */

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
