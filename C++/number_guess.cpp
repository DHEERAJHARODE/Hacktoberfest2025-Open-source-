#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

/**
 * @brief Simple Number Guessing Game.
 * The computer picks a random number, and the user tries to guess it.
 */
int main() {
    // 1. Seed the random number generator
    // This makes sure the sequence of random numbers is different each time
    srand(time(0));

    // 2. Define the range and pick a random number
    const int MIN_NUM = 1;
    const int MAX_NUM = 100;
    
    // Generate a random number between MIN_NUM and MAX_NUM (inclusive)
    int secretNumber = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
    
    int guess = 0;
    int attempts = 0;

    std::cout << "--- The Number Guessing Game ---\n";
    std::cout << "I have picked a secret number between " << MIN_NUM 
              << " and " << MAX_NUM << ".\n";
    std::cout << "Can you guess it?\n\n";

    // 3. Game Loop
    while (guess != secretNumber) {
        std::cout << "Enter your guess: ";
        
        // Input validation (optional, but good practice)
        if (!(std::cin >> guess)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); // Clear the error flags
            std::cin.ignore(10000, '\n'); // Discard bad input
            continue; // Skip the rest of the loop
        }

        attempts++; // Increment the attempt counter

        // 4. Check the guess
        if (guess < secretNumber) {
            std::cout << "Too low! Try again.\n";
        } else if (guess > secretNumber) {
            std::cout << "Too high! Try again.\n";
        } else {
            // guess == secretNumber
            std::cout << "\n****************************************\n";
            std::cout << "🎉 Congratulations! You guessed the number!\n";
            std::cout << "It took you " << attempts << " attempts.\n";
            std::cout << "****************************************\n";
        }
    }

    return 0;
}