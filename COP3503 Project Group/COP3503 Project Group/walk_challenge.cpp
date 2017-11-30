//  walk_challenge.cpp
//  COP3503 Project Group

//  Copyright © 2017 Group 35. All rights reserved.
//

#include <iostream>
#include <math.h>
#include "walk_challenge.hpp"

void walkChallenge:: go(){
	
	string item;
	
	int xPosOrNeg = rand() % 2 + 1;
	int yPosOrNeg = rand() % 10 + 1;
	
	int itemXcor = 5 + (rand() * (int)(10 - 5) / 10);
	int itemYcor = 5 + (rand() * (int)(10 - 5) / 10);
	
	int playerXcor = 0;
	int playerYcor = 0;
	
	if (xPosOrNeg == 2){
		itemXcor = -itemXcor;
	}
	if (yPosOrNeg == 2){
		itemYcor = -itemYcor;
	}
	int playerChoice;
	while (itemXcor != playerXcor && itemXcor != playerYcor){
		int distance = sqrt(pow(itemXcor-playerXcor, 2) + pow(itemYcor-playerYcor, 2));
		cout << "You are " << distance << "units away from the item" << endl;
		while (playerChoice != 1, playerChoice != 2, playerChoice != 3, playerChoice != 4){
			cout << "Please select which direction you would like to move:\n1. Left\n2. Right\n3. Forward\n4. Backwards" << endl;
			cin >> playerChoice;
			
			if (playerChoice == 1){
				playerXcor--;
			} else if (playerChoice == 2){
				playerXcor++;
			} else if (playerChoice == 3){
				playerYcor++;
			} else if (playerChoice == 4){
				playerYcor--;
			}
		}
	}
	cout << "You have reached the item!" << endl;
	cout << "It is " << item << endl;
	
	//must return string
	return item;
}
