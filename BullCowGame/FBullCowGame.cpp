#include "FBullCowGame.h"

void FBullCowGame::Reset()
{
	return;
}


int FBullCowGame::GetMaxTries()
{
	return this->MyMaxTries;
}

int FBullCowGame::GetCurrentTry()
{
	return this->MyCurrentTry;
}


bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}


bool FBullCowGame::IsGameWon()
{
	return false;
}
