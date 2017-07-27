#include "FBullCowGame.h"

int FBullCowGame::GetMaxTries() const { return this->MyMaxTries; }
int FBullCowGame::GetCurrentTry() const { return this->MyCurrentTry; }


// Constructor
FBullCowGame::FBullCowGame()
{
	this->Reset();
}

FBullCowGame::~FBullCowGame()
{
}

void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 8;
	this->MyCurrentTry = 1;
	this->MyMaxTries = MAX_TRIES;
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
