/* This is the  console executable, that makes use  of the BullCow class
This acts as view in a MVC pattern and its  responsible for all
user interaction. For game logic see the FBullCowGame class.
*/


#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro(FBullCowGame &BCGame);
FText GetValidGuess(FBullCowGame &BCGame);
void PlayGame(FBullCowGame &BCGame);
bool AskToPlayAgain();
void PrintGameSummary(FBullCowGame &BCGame);
int32 GetGameDificulty(FBullCowGame &BCGame);





int main() 
{
	//Create instace of FBullCowGame

	FBullCowGame BCGame;
	bool bPlayAgain = false;
	do
	{
		PrintIntro(BCGame);
		PlayGame(BCGame);
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	return 0;
}


void PlayGame(FBullCowGame &BCGame)
{
	int32 length = GetGameDificulty(BCGame);

	BCGame.Reset(length);
	int32 MaxTries = BCGame.GetMaxTries();
	//Loop asking for guess while the game is not Won 
	//and there are tries left
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess(BCGame);
		//submit valid guess to game and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
		std::cout << std::endl;
	}
	PrintGameSummary(BCGame);
}


//Get guess from user
FText GetValidGuess(FBullCowGame &BCGame)
{
	EGuessStatus Status = EGuessStatus::Invalid;
	FText Guess = "";
	do
	{
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries() << " - ";
		std::cout << "Enter your guess: ";
		std::getline(std::cin, Guess);
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Invalid_Lenght:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters\n\n";
			break;
		case EGuessStatus::Not_LowerCase:
			std::cout << "Please enter all lower case letters.\n\n";
			break;
		default: 
			//Valid Guess
			break;
		}

	} while (Status != EGuessStatus::OK); //keep looping until no errors

	return Guess;
}


//Introduce the game
void PrintIntro(FBullCowGame &BCGame)
{
	std::cout << "Welcome to Bulls & Cows, a fun word game\n";
	std::cout << "  ,           ,\n";
	std::cout << "   /             \\\n";
	std::cout << "  ((__-^^-,-^^-__))\n";
	std::cout << "   `-_---' `---_-'\n";
	std::cout << "    <__|o` 'o|__>\n";
	std::cout << "       \  `  /\n";
	std::cout << "        ): :(\n";
	std::cout << "        :o_o:\n";
	std::cout << "       " "-" " \n";
	std::cout << std::endl;

}

void PrintGameSummary(FBullCowGame &BCGame)
{
	if (BCGame.IsGameWon())
	{
		std::cout << "Congratulations - You Won Bulls&Cows!\n\n";
	}
	else
	{
		std::cout << "You failed to guess the hidden word. Better luck next time!\n\n";
	}

}

int32 GetGameDificulty(FBullCowGame &BCGame)
{
	int32 length = 0;
	do
	{
		std::cout << "Please choose the size of the hidden word(from 1 to 7): ";
		std::cin >> length;
		if (length < 1 || length > 7)
			std::cout << "Please choose a size between 1 and 7 \n";
	} while (length < 1 || length >7);
	return length;
}


bool AskToPlayAgain()
{
	std::cout << "Do you wish to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}