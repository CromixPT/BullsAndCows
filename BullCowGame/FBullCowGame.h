#pragma once
#include <string>

class FBullCowGame {
public:
	void Reset();
	int GetMaxTries();
	int GetCurrentTry();
	bool CheckGuessValidity(std::string);
	bool IsGameWon();

private:
	int MyCurrentTry;
	int MyMaxTries;
};