//  main.cpp
//  COP3503 Project Group

//  Copyright © 2017 Group 35. All rights reserved.

#include <iostream>
#include "game_engine.hpp"

int main(int argc, const char * argv[]) {
   
    std::cout << "Welcome to a mystical adventure through COP 3502. Your programming assignment has a nasty bug in it, and it is up to you to reach the dungeon and fix it before the submission deadline. If you fail this assignment, you can kiss your grade goodbye. There will be many perils on your quest. Many will obstruct your path to an A.\n\n";
  
    std::cout << "O terminal soldier, what is your name?\n";
   
    std::string name = "";
    std::cin >> name;
   
    Player * p = new Player(name);
    std::queue<Room *> * roomList = new std::queue<Room *>();

    challenge c = challenge();
   
    std::string message = "It is 7:25 AM, and you're wishing you could be anywhere but here. Your mind can do nothing but wander, try as you might to focus.\nYes - you're in NPB 1001.\n";
   
    std::string flavorText = "Since your mind is already wandering, this is not difficult to do. The ten other people in the room are all buried in their laptop screens, checking Reddit, Canvas, or what have you. You feel like nobody would notice if you left.\n";
  
    std::vector<std::string> choices = {
	"See what everyone else is up to.",
	"Ask the professor a question.",
	"Look for a way to unlock the door.",
	"Try and sneak out."
    };
   
    Monster m = Monster(5, 5, 11, 8, 10, 30, "DR. KAVALAN");
    Room * r = new Room(&c, &m, message, flavorText, choices);
    roomList->push(r);

// The following lines are a template for more rooms.
    c = challenge();
    
    message = ""; // Insert room-entry message here.
   
    flavorText = ""; // Insert "examine" text here.
   
    choices = {
	"", // Insert "examine" choice here.
	"", // Insert "battle" choice here.
	"", // Insert "challenge" choice here.
	"" // Insert "leave" choice here.
    };
   
    m = Monster(0, 0, 0, 0, 0, 0, ""); // Insert, in this order, the HP, max HP, STR, DEF, STA, EXP yield upon death, name.
    r = new Room(&c, &m, message, flavorText, choices);
    roomList->push(r);
// The previous lines are a template for more rooms.

    GameEngine * g = new GameEngine(p, roomList);
    g->go();

    delete p;
    delete[] roomList;
    delete[] g;
    return 0;
}
