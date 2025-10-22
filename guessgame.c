// Simple Number Guessing Game
// Compile: gcc -o guess_game guess_game.c
// Run: ./guess_game

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_game(int max_number, int max_attempts) {
    int secret, guess, attempts = 0;
    secret = (rand() % max_number) + 1;

    printf("I've picked a number between 1 and %d. You have %d attempts.\n", max_number, max_attempts);

    while (attempts < max_attempts) {
        attempts++;
        printf("Attempt %d: Enter your guess: ", attempts);
        if (scanf("%d", &guess) != 1) {
            // Handle non-integer input
            printf("Please enter a valid integer.\n");
            // flush stdin
            int c; while ((c = getchar()) != '\n' && c != EOF) {}
            attempts--;
            continue;
        }

        if (guess == secret) {
            printf("🎉 Correct! You guessed the number %d in %d attempt(s).\n", secret, attempts);
            return;
        } else if (guess < secret) {
            printf("Too low.\n");
        } else {
            printf("Too high.\n");
        }
    }

    printf("😢 Out of attempts. The number was %d. Better luck next time!\n", secret);
}

int main() {
    srand((unsigned) time(NULL)); // seed RNG

    char choice = 'y';
    while (choice == 'y' || choice == 'Y') {
        printf("\nChoose difficulty: (1) Easy (1-20, 7 attempts)\n");
        printf("                 (2) Medium (1-50, 6 attempts)\n");
        printf("                 (3) Hard (1-100, 5 attempts)\n");
        printf("Enter 1, 2 or 3: ");

        int diff;
        if (scanf("%d", &diff) != 1) {
            printf("Invalid input. Defaulting to Medium.\n");
            diff = 2;
            int c; while ((c = getchar()) != '\n' && c != EOF) {}
        }

        if (diff == 1) play_game(20, 7);
        else if (diff == 3) play_game(100, 5);
        else play_game(50, 6);

        printf("Play again? (y/n): ");
        // consume leftover newline before reading char
        int c; while ((c = getchar()) != '\n' && c != EOF) {}
        choice = getchar();
    }

    printf("Thanks for playing! 🎮\n");
    return 0;
}
