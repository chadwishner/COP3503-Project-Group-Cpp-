#define quiz_challenge_hpp
#include "challenge.hpp"
#include <stdio.h>

using namespace std;

class quizchallenge : public challenge{
private:
    int room;
    int trivia;
public:
    quizchallenge(int room){
        this -> room = room;
    }
    void go();
};

