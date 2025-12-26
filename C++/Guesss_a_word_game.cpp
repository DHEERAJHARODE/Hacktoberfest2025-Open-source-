#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to choose a random word from an array
string chooseRandomWord() {
    vector<string> words = {"apple", "banana", "chocolate", "elephant", "programming", "hangman", "computer", "keyboard"};
    int randomIndex = rand() % words.size();
    return words[randomIndex];
}

// Function to display the current state of the word with guessed letters
void displayWord(const string& secretWord, const vector<bool>& guessed) {
    for (int i = 0; i < secretWord.length(); ++i) {
        if (guessed[i]) {
            cout << secretWord[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

int main() {
    srand(time(0));
    string secretWord = chooseRandomWord();
    int attempts = 6; // Number of incorrect attempts allowed
    vector<bool> guessed(secretWord.length(), false);
    char guess;

    cout << "Welcome to Hangman!" << endl;

    while (attempts > 0) {
        cout << "Attempts left: " << attempts << endl;
        displayWord(secretWord, guessed);
        cout << "Guess a letter: ";
        cin >> guess;

        bool found = false;

        for (int i = 0; i < secretWord.length(); ++i) {
            if (secretWord[i] == guess && !guessed[i]) {
                guessed[i] = true;
                found = true;
            }
        }

        if (!found) {
            cout << "Incorrect guess!" << endl;
            attempts--;
        }

        // Check if the player has guessed all the letters
        bool allGuessed = true;
        for (bool letterGuessed : guessed) {
            if (!letterGuessed) {
                allGuessed = false;
                break;
            }
        }

        if (allGuessed) {
            cout << "Congratulations! You guessed the word: " << secretWord << endl;
            break;
        }
    }

    if (attempts == 0) {
        cout << "Sorry, you're out of attempts. The word was: " << secretWord << endl;
    }

    return 0;
}
