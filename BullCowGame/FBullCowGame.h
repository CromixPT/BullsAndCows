#pragma once
#include <string>

//look a me

class FBullCowGame {
public:
	FBullCowGame(); // Constructor
	~FBullCowGame(); // Destructor
	void Reset(); //TODO make a more rich return
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool CheckGuessValidity(std::string) const;//TODO make a more rich return
	bool IsGameWon() const;

	//provide a method for counting bulls and cows and increasing try number



private:
	int MyCurrentTry;
	int MyMaxTries;

};