#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); 
    int secretNumber = rand() % 100 + 1; 
    int attempts = 0;
    int guess;

    cout << "Welcome to the Guessing Game!" << endl;
    cout << "I have selected a random number between 1 and 100. Try to guess it!" << endl;

    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess == secretNumber) {
            cout << "Congratulations! You guessed the secret number " << secretNumber << " in " << attempts << " attempts." << endl;
            break;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Too high! Try again." << endl;
        }

        if (attempts >= 10) {
            cout << "Sorry, you've reached the maximum number of attempts. The secret number was " << secretNumber << "." << endl;
            break;
        }
    }

    return 0;
}
