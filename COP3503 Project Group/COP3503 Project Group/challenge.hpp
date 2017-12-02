//  challenge.hpp
//  COP3503 Project Group

//  Copyright © 2017 Group 35. All rights reserved.

#ifndef challenge_hpp
#define challenge_hpp

#include <string>

using namespace std;

class challenge {
	private:		string item;
					int challengeType;
					void walkChallenge();
					void quizChallenge();
	public:			string go();
					challenge();
					challenge(int challengeType, string item);
};

#endif /* challenge_hpp */
