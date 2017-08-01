#include "FBullCowGame.h"
#include <map>
#define TMap std::map



using int32 = int;


int32 FBullCowGame::GetCurrentTry() const { return this->MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const  {	return this->bGameIsWon; }



FString FBullCowGame::SetHiddenWord(int32 &Length)
{
	TMap<int32, FString> HiddenWord{ {3,"gas"},{4,"fork"},{5,"table"},{6,"planet"},{7,"bailout"} };
	return HiddenWord[Length];
}



// Constructor
FBullCowGame::FBullCowGame()
{
//	this->Reset();
}


int32 FBullCowGame::GetMaxTries() const 
{ 
	TMap<int32, int32> MaxTriesRelation{ {3,6},{4,8},{5,10},{6,12} , {7,14} };
	return MaxTriesRelation[MyHiddenWord.length()];
}


FBullCowGame::~FBullCowGame()
{
}

void FBullCowGame::Reset(int32 &Length)
{

	this->MyCurrentTry = 1;
	this->MyHiddenWord = SetHiddenWord(Length);
	this->bGameIsWon = false;

	return;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	//if the guess isn't an isogram 
	if (!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram; //TODO make isogram check method
	}
	//if the guess isn't all lower case
	else if (!IsLowerCase(Guess)) 
	{
		return EGuessStatus::Not_LowerCase; //TODO make lower case check method
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
	if (BullCowCount.Bulls == WordLength)
	{
		this->bGameIsWon = true;
	}
	else
	{
		this->bGameIsWon = false;
	}
	return BullCowCount;
}


bool FBullCowGame::IsIsogram(FString Word) const
{
	//treat  0 and 1 letter words  as isograms
	if (Word.length() <= 1) { return true; }
	//setup map
	TMap<char, bool> LetterSeen;
	//loop all letters in guess word
	for (auto Letter : Word)
	{
		Letter = tolower(Letter); // Handle mixed cases
		//if the letter is in the map
		if (LetterSeen[Letter])
			return false; 		//we do not have an isogram
		else
			LetterSeen[Letter] = true;		//otherwise add to the map
	}
	return true;
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
	if (Word.length() <= 1) { return true; }
	for (auto Letter : Word)
	{
		if (!islower(Letter))
		{
			return false;
		}
	}
	return true;
}
