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
					void walkChallenge(); // two different challenge functions
					void quizChallenge();
	public:			string go();
					challenge(); // an empty constructor if  challenge is not specified
					challenge(int challengeType, string item);// constructor if key is needed to be put in room and and if challengetype needas to be declared
};

#endif /* challenge_hpp */
