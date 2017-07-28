#include "FBullCowGame.h"

using int32 = int;

int32 FBullCowGame::GetMaxTries() const { return this->MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return this->MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }


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
	const FString HIDDEN_WORD = "ant";


	this->MyCurrentTry = 1;
	this->MyMaxTries = MAX_TRIES;
	this->MyHiddenWord = HIDDEN_WORD;

	return;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	//if the guess isn't an isogram 
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	//if the guess isn't all lower case
	else if (false)
	{
		return EGuessStatus::Not_LowerCase;
	}
	//if the guess leght is wrong
	else if (GetHiddenWordLength() != Guess.length())
	{
		return EGuessStatus::Invalid_Lenght;
	}
	//otherwise
	else
	{
		return EGuessStatus::OK;
	}
}


bool FBullCowGame::IsGameWon() const
{
	return false;
}


//receives a valid guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	this->MyCurrentTry++;
	FBullCowCount BullCowCount;
	//loop through all the letters in the hidden word
	int32 WordLength = this->MyHiddenWord.length(); // assuming same length as Guess
	for(int32 MHWChar=0; MHWChar< WordLength; MHWChar++)
	{
		//compare letters against the  guess
		for(int32 GChar=0; GChar< WordLength; GChar++)
		{ 
			//if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{
				//if they're in the same place
				if(GChar==MHWChar) 
				{
					//increment bulls 
					BullCowCount.Bulls++;
				}
				else
				{
					//increment cows if not
					BullCowCount.Cows++;
				}
			}
		}
	}
	return BullCowCount;
}
