/* This is the  console executable, that makes use  of the BullCow class
This acts as view in a MVC pattern and its  responsible for all
user interaction. For game logic see the FBullCowGame class.
*/


#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
FText GetValidGuess();
void PlayGame();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame;

int main() 
{

	
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	return 0;
}


void PlayGame()
{
	//Create instace of FBullCowGame
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	//Loop asking for guess while the game is not Won 
	//and there are tries left
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();  
		//submit valid guess to game and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
		std::cout << std::endl;
	}
	PrintGameSummary();
}


//Get guess from user
FText GetValidGuess()
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
void PrintIntro()
{
	std::cout << "Welcome to Bulls & Cows, a fun word game\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram in ";
	std::cout << BCGame.GetMaxTries() << " tries!\n\n";
	return;
}

void PrintGameSummary()
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


bool AskToPlayAgain()
{
	std::cout << "Do you wish to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}