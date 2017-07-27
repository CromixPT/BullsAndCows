#pragma once
#include <string>

using FString = std::string;
using int32 = int;

//All values initialized to 0.	
struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame 
{
public:
	FBullCowGame(); // Constructor
	~FBullCowGame(); // Destructor
	void Reset(); //TODO make a more rich return
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool CheckGuessValidity(FString) const;//TODO make a more rich return
	bool IsGameWon() const;
	//FString GetHiddenWord() const;

	//counts bulls and cows and increasing try number, assumes a valid guess
	FBullCowCount SubmitGuess(FString);


private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;

};