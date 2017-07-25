#include <iostream>
#include <string>

void PrintIntro();
std::string GetGuess();

int main() 
{
	PrintIntro();
	constexpr int MAX_TRIES = 5;
	for (int count = 1; count <= MAX_TRIES; ++count)
	{
		std::cout << "Your guess was: " << GetGuess() << std::endl;
		std::cout << std::endl;
	}
	return 0;
}


//Get guess from user
std::string GetGuess()
{
	std::string Guess = "";
	std::cout << "Input your guess: ";
	std::getline(std::cin, Guess);
	std::cin.sync();
	return Guess;
}

//Introduce the game
void PrintIntro()
{
	constexpr int WORD_LEGHT = 5;
	std::cout << "Welcome to Bulls & Cows, a fun word game\n";
	std::cout << "Can you guess the " << WORD_LEGHT;
	std::cout << " letter isogram I'm thinking of?\n\n";
	return;
}
