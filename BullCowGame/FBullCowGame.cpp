#include "FBullCowGame.h"

int FBullCowGame::GetMaxTries() const { return this->MyMaxTries; }
int FBullCowGame::GetCurrentTry() const { return this->MyCurrentTry; }

void FBullCowGame::Reset()
{
	return;
}


bool FBullCowGame::CheckGuessValidity(std::string) const
{
	return false;
}


bool FBullCowGame::IsGameWon() const
{
	return false;
}
