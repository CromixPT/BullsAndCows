#pragma once
#include <string>

//look a me

class FBullCowGame {
public:
	void Reset();
	int GetMaxTries();
	int GetCurrentTry();
	bool CheckGuessValidity(std::string);
	bool IsGameWon();

private:
	int MyCurrentTry = 1;
	int MyMaxTries =5;

};