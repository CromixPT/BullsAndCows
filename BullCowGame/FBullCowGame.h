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

enum class EGuessStatus
{
	Invalid,
	OK,
	Not_Isogram,
	Invalid_Lenght,
	Not_LowerCase,
};

class FBullCowGame 
{
public:
	FBullCowGame(); //Construtor for hidden word size selection
	~FBullCowGame(); // Destructor
	void Reset(int32&); //TODO make a more rich return
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	FString SetHiddenWord(int32&);
	EGuessStatus CheckGuessValidity(FString) const;//TODO make a more rich return
	bool IsGameWon() const;
	
	//FString GetHiddenWord() const;

	//counts bulls and cows and increasing try number, assumes a valid guess
	FBullCowCount SubmitValidGuess(FString);


private:
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;
	bool IsIsogram(FString Word ) const;
	bool IsLowerCase(FString Word) const;

};