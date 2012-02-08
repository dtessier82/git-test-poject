#include "StdAfx.h"
#include "Game.h"
#include "Player.h"
#include <stdio.h>

enum
{
    PAPER = 1,
    ROCK = 2,
    SCISSOR = 3
};
int const MAX_ROUNDS = 5;

Game::Game(void)
{
    this->player = 0;
    this->rounds = 0;
    this->gameOver = false;
    this->cpuScore =0;
    this->cpuChoice=0;
}

void Game::createPlayer()
{
    string name;
    cout << "Enter Player 1 Name: ";
    cin >> name;
    player = new Player(name);
}

void Game::getPlayerInput()
{
    int choice = 0;
    cout << "Please make a choice (1=Paper, 2=Rock, 3=Scissors): ";
    cin >> choice;
    this->player->setPlayerChoice(choice);
}

void Game::playGame()
{
    this->createPlayer();
    cout << "Welcome, " + this->player->getPlayerName() +"\r\n";
    while(!gameOver)
    {
        this->getPlayerInput();
        this->updateCPUSelection();
        this->validate();
        this->updateScore();
    }
   
}

void Game::updateScore()
{
   
    string p1 = this->player->getPlayerName();
    int p1Score = this->player->getPlayerScore();

    printf("\r\nAfter round: %i the score is :\r\n", this->rounds);
    printf("Player 1: %s %c %i \r\n", p1, ":", p1Score);
    printf("CPU : %i \r\n",this->cpuScore);
}

void Game::validate()
{
    if(this->rounds == MAX_ROUNDS){
        this->gameOver = true;
        return;
    }

    int pChoice = this->player->getPlayerChoice();
    switch(pChoice)
    {
        case PAPER:
            if(this->cpuChoice == PAPER){
                // tie
                this->player->updatePlayerScore();
                this->cpuScore+=1;
            }else if(this->cpuChoice == ROCK){
                this->player->updatePlayerScore();
            }else{
                this->cpuChoice +=1;
            }
            break;
        case ROCK:
             if(this->cpuChoice == ROCK){
                // tie
                this->player->updatePlayerScore();
                this->cpuScore+=1;
            }else if(this->cpuChoice == SCISSOR){
                this->player->updatePlayerScore();
            }else{
                this->cpuChoice +=1;
            }
            break;
        case SCISSOR:
              if(this->cpuChoice == SCISSOR){
                // tie
                this->player->updatePlayerScore();
                this->cpuScore+=1;
            }else if(this->cpuChoice == PAPER){
                this->player->updatePlayerScore();
            }else{
                this->cpuChoice +=1;
            }
            break;
        default:
            this->gameOver = true; // invalid selection
            break;
    }

    this->rounds+=1; // update rounds played
}

void Game::updateCPUSelection()
{
    srand(time(0)); // initialize seed
    this->cpuChoice = rand() % 3 + 1; // random number between 1 - 3
}

Game::~Game(void)
{
    delete player;
}
