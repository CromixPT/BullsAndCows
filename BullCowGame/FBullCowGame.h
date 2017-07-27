#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame {
public:
	FBullCowGame(); // Constructor
	~FBullCowGame(); // Destructor
	void Reset(); //TODO make a more rich return
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool CheckGuessValidity(FString) const;//TODO make a more rich return
	bool IsGameWon() const;

	//provide a method for counting bulls and cows and increasing try number



private:
	int32 MyCurrentTry;
	int32 MyMaxTries;

};