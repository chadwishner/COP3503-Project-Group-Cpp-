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

//  Room 1 : NPB 1001
    
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
    
//  Room 2 : Bookstore
    
    challenge c2 = challenge(2, "key");
    std::string message2 = "After that experience, you decide to pay a visit the campus bookstore. Yes, the prices here are exorbitantly high, but at this point, you might be able to get more out of a textbook than a 7:25 lecture. Perhaps you will be able to find a clue here to help you debug your program.";
    std::string flavorText2 = "You pick up the nearest copy of C++ Primer, Fifth Edition and begin to flip through the pages. This would be a convenient resource, if not for the fact that it's nearly 1000 pages long. Stack Overflow would be much more helpful here.";
    std::vector<std::string> choices2 = {
        "Open up a C++ textbook.",
        "Wander the shelves.",
        "Talk to an employee.",
        "Leave the bookstore."
    };
    Monster m2 = Monster(8, 8, 13, 10, 15, 45, "overpriced textbook");
    Room * r2 = new Room(&c, &m, message, flavorText, choices);
    roomList->push(r2);
    
//  Room 3 goes here
    challenge c3 = challenge(1, "key");
    
    std::string message3 = "Heed this warning young student. Many juniors-by-credits have attempted this quest and met their ultimate demise. Do you have the grit to engage in battle with such a terrifying opponent? As you enter this faintly familiar establishment, you must decide your course of action.”;
    
    std:: string flavorText3 = "You can hear faint 2015 top ten hits in the distance. The aroma of deep fried potatoes and chicken fill your nostrils. You hear “cha-ching” as flex bucks vanish into the meal plan abyss. The doors lock all around you. Where ever could you be? That’s right. Broward Chick-Fil-A. As the chills creep up your spine, you feel a being staring from behind. As you turn around slowly, you see it. The Chick-Fil-A cow. He bellows “EAT MORE CHICKEN” as he charges you in attack mode. As he approaches, you spot a deep fried key shimmering at the cash register. Maybe, just maybe, you could evade the cow, grab it, and make your escape.“;
    
    std::vector<std::string> choices3 = {
        "Look around.“,
        "Engage the Chick-Fil-A Cow.”,
        "Dodge the cow, dash for the key.”,
        "Make your way over to the exit, unlock the door, and continue your journey.”
    };
    Monster m3 = Monster(0, 0, 0, 0, 0, 0, "Chick-Fil-A Cow");
    Room * r3 = new Room(&c, &m, message, flavorText, choices);
    roomList->push(r3);

    
    //room 4 goes here
    
    
    //room 5 goes here
    
    
    //room 6 goes here
    
    
    //room 7 goes here
    challenge c7 = challenge(1, "key");
    
    std::string message3 = "As you walk along the path, you near your destination. You pass sign after sign telling you to turn back. As you get closer, the faint sounds of voices get louder and louder. Soon, you hear a sea of foot traffic. You can hear clubs recruiting and fundraising from a mile away. Your eyes widen as your realize where you are. You’re standing in the center of Turlington.”;
    
    std:: string flavorText3 = "As you scan the landscape, you spot a few things through the crowd. You see a science library, a glowing potato looking monstrosity, and a gator growl fundraiser verbally assaulting other students. You stop to notice a muscular-legged silhouette. You see a hand shoot up in the shape of a peace sign. There’s no mistake, it’s Dennis, The Peace Guy. His insanely toned quads propel him towards you.“;
    
    std::vector<std::string> choices3 = {
        "Look around.“,
        "Engage Dennis in battle.”,
        "Dodge Dennis, dash for the glowing potato.”,
        "Open the door to the Computer Science and Engineering Building.”
    };
    Monster m4 = Monster(0, 0, 0, 0, 0, 0, "Dennis, The Peace Guy");
    Room * r4 = new Room(&c, &m, message, flavorText, choices);
    roomList->push(r4);
    
    //room 8 goes here
    
    
    
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
