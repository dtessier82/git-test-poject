// PaperRockScissors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h";
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
    Game* game = new Game();
    game->playGame();
	return 0;
}

