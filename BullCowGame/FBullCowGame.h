#pragma once
#include <string>

//look a me

class FBullCowGame {
public:
	void Reset();
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool CheckGuessValidity(std::string) const;
	bool IsGameWon() const;

private:
	int MyCurrentTry = 1;
	int MyMaxTries =5;

};