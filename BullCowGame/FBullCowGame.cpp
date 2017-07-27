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
	const FString HIDDEN_WORD = "Planet";
	this->MyHiddenWord = HIDDEN_WORD;
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


//receives a valid guess, increments turn and returns count
BullCowCount FBullCowGame::SubmitGuess(FString)
{
	//increment the turn number
	this->MyCurrentTry++;
	//setup a return variable
	BullCowCount BullCowCount;
	//loop through all the letters in the guess
		//compare letters against the hidden word
	return BullCowCount;
}
