#pragma once
#include <string>

//look a me

class FBullCowGame {
public:
	FBullCowGame(); // Constructor
	~FBullCowGame(); // Destructor
	void Reset();
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool CheckGuessValidity(std::string) const;
	bool IsGameWon() const;

private:
	int MyCurrentTry;
	int MyMaxTries;

};