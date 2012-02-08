#include "Player.h";

// prevent multiple inclusions of header
#ifndef GAME_H
#define GAME_H
#pragma once
class Game
{
public:
    Game(void);
    ~Game(void);
    void playGame();
    void createPlayer();
    void getPlayerInput();
    void updateCPUSelection();
    void validate(); 
    void updateScore();
private:
    Player* player;
    int rounds;
    int cpuChoice;
    int cpuScore;
    bool gameOver;
};

#endif

