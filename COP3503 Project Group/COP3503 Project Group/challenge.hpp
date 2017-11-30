//
//  challenge.hpp
//  COP3503 Project Group
//
//  Created by Chad Wishner on 11/5/17.
//  Copyright © 2017 Group 35. All rights reserved.
//

#ifndef challenge_hpp
#define challenge_hpp

#include <string>

using namespace std;

class challenge {
	protected:		string item;
	public:			string go(string item);
};

void walkChallenge(string item);
void quizChallenge(string item);
#endif /* challenge_hpp */
