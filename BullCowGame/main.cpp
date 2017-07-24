#include <iostream>
#include <string>

int main() {

	//Introduce the game
	constexpr int WORD_LEGHT = 5;
	std::cout << "Welcome to Bulls & Cows, a fun word game\n";
	std::cout << "Can you guess the " << WORD_LEGHT;
	std::cout << " letter isogram I'm thinking of?\n";

	std::string Guess = "";

	// get a guess form user
	std::cout << "Input your guess: ";
	std::getline(std::cin, Guess);
	//repeat the guess back to user
	std::cout << "Your guess was: " << Guess << std::endl;
	std::cin.sync();

	// get a guess form user
	std::cout << "Input your guess: ";
	std::getline(std::cin, Guess);
	//repeat the guess back to user
	std::cout << "Your guess was: " << Guess << std::endl;



	return 0;
}