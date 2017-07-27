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
FText GetGuess();
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
		FText Guess = GetGuess();  // TODO check for valid guesses

		//submit valid guess to game
		//print number of bulls and cows


		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}

	//TODO summarise the game
}


//Get guess from user
FText GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	FText Guess = "";
	std::cout << "Try " << CurrentTry << ". ";
	std::cout << "Enter your guess: ";
	std::getline(std::cin, Guess);
	//std::cin.sync();
	return Guess;
}


//Introduce the game
void PrintIntro()
{
	constexpr int32 WORD_LEGHT = 5;
	std::cout << "Welcome to Bulls & Cows, a fun word game\n";
	std::cout << "Can you guess the " << WORD_LEGHT;
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