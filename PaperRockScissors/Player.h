#include <string>
using namespace std;

// prevent multiple inclusions of header
#ifndef PLAYER_H
#define PLAYER_H

#pragma once
class Player
{
public:
    Player(string);
    ~Player(void);
    string getPlayerName() const;
    void setPlayerChoice(int);
    int getPlayerChoice();
    void updatePlayerScore();
    int getPlayerScore();
private:
    string playerName;
    int playerChoice;
    int playerScore;
};

#endif

