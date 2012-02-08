#include "StdAfx.h"
#include "Player.h"


Player::Player(string name)
{
    this->playerName = name;
    this->playerScore = 0;
}


string Player::getPlayerName() const
{
    return this->playerName + "somthing else";
}

void Player::setPlayerChoice(int choice)
{
    this->playerChoice = choice;
}

int Player::getPlayerChoice()
{
    return this->playerChoice;
}

int Player::getPlayerScore()
{
    return this->playerScore;
}

void Player::updatePlayerScore()
{
    this->playerScore += 1;
}

Player::~Player(void)
{
    this->playerName="";
    this->playerChoice=NULL;
}
