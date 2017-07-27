#include "FBullCowGame.h"

using int32 = int;

int32 FBullCowGame::GetMaxTries() const { return this->MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return this->MyCurrentTry; }


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
	constexpr int32 MAX_TRIES = 8;
	this->MyCurrentTry = 1;
	this->MyMaxTries = MAX_TRIES;
	return;
}


bool FBullCowGame::CheckGuessValidity(FString) const
{
	return false;
}


bool FBullCowGame::IsGameWon() const
{
	return false;
}
