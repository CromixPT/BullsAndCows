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
	std::cout << "Maximum tries: " << MaxTries << std::endl;
	//Loop for the number of turns asking for guess
	//TODO change from for to while
	for (int32 count = 1; count <= MaxTries; ++count)
	{
		FText Guess = GetValidGuess();  

	
		//submit valid guess to game and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;


		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}

	//TODO summarise the game
}


//Get guess from user
FText GetValidGuess() //TODO Change to GetValidGuess
{
	EGuessStatus Status = EGuessStatus::Invalid;
	do
	{
		int32 CurrentTry = BCGame.GetCurrentTry();
		FText Guess = "";
		std::cout << "Try " << CurrentTry << ". ";
		std::cout << "Enter your guess: ";
		std::getline(std::cin, Guess);
		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);

		switch (Status)
		{
		case EGuessStatus::Invalid_Lenght:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters\n";
			break;
		case EGuessStatus::Not_LowerCase:
			std::cout << "Please enter all lower case letters.\n";
			break;
		default:
			return Guess;
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK); //keep looping until no errors
}


//Introduce the game
void PrintIntro()
{
	std::cout << "Welcome to Bulls & Cows, a fun word game\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n\n";
	return;
}


bool AskToPlayAgain()
{
	std::cout << "Do you wish to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}